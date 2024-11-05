/************************************************************************
 * \file CloverQuadBuchDetector.hh
 *
 * \class CloverQuadBuchDetector
 * \brief Design of a HPGe detector crystal (Clover 40x50x70) (Bucharest)
 *
 * \author Christophe Sotty : csotty@gmail.com
 *                            Christophe.Sotty@fys.kuleuven.be
 *
 *************************************************************************/
//R. Lica on 01.03.2016 - Fixed the G4Transform3D bug, removed det_env

#include <TText.h>
#include "IS659Clovers.hh"
#include "G4VisAttributes.hh"
#include "G4SystemOfUnits.hh"
#include "G4NistManager.hh"
#include "CADMesh.hh"

#ifdef Error
#undef Error
#endif


using namespace std;


//lazily build everything aluminum in this class

IS659Clovers::IS659Clovers(G4VPhysicalVolume* p_mother, G4double p_rho, G4double p_theta, G4double p_phi, G4double p_spin)
        :mother(p_mother), rho(p_rho), theta(p_theta), phi(p_phi), spin(p_spin)
{
    //G4cout	<<"\nClover Quad (Bucharest) DETECTOR#######################\n"	<<flush
    //	<<"\nRho =\t\t"		<<rho/mm	<< " mm"	<<flush
    //	<<"\nTheta =\t\t"	<<theta/deg	<< " deg" 	<<flush
    //	<<"\nPhi =\t\t"		<<phi/deg	<< " deg"       <<flush
    //	<<"\nSpin =\t\t"	<<spin/deg	<< " deg"       <<flush
    //	<<"\nCloverNb =\t"	<<cl_nb 			<<G4endl;
}

IS659Clovers::~IS659Clovers()
{;}


G4VPhysicalVolume* IS659Clovers::Construct()
{
    // Material
    //
    G4NistManager* NISTmgr = G4NistManager::Instance();

    G4Material* Vacuum          = NISTmgr->FindOrBuildMaterial("G4_Galactic");
    G4Material* Air             = NISTmgr->FindOrBuildMaterial("G4_AIR");
    G4Material* Al_mat          = NISTmgr->FindOrBuildMaterial("G4_Al");
    G4Material* Ge_mat          = NISTmgr->FindOrBuildMaterial("G4_Ge");
    G4Material* Steel_mat       = NISTmgr->FindOrBuildMaterial("G4_STAINLESS-STEEL");
    G4Material* ln2_mat         = NISTmgr->BuildMaterialWithNewDensity("LN2","G4_N", 0.81 * g/cm3, 1);


    // Visualisation
    //
    G4VisAttributes* tapeBoxVisAtt = new G4VisAttributes( G4Colour(0.3,0.3,0.3));
    tapeBoxVisAtt->SetForceAuxEdgeVisible(true);// Can see outline when drawn with lines
    //tapeBoxVisAtt->SetForceSolid(true);
    frame_vis_att       = tapeBoxVisAtt;

    //tesselated mesh
    auto casingsTessMesh = CADMesh::TessellatedMesh::FromSTL("../stl/isolde/IS659/CloverCasings.stl");
    auto fixingsTessMesh = CADMesh::TessellatedMesh::FromSTL("../stl/isolde/IS659/CloverFixings.stl");
    auto dewarsTessMesh = CADMesh::TessellatedMesh::FromSTL("../stl/isolde/IS659/CloverDewars.stl");
    auto crystalsTessMesh = CADMesh::TessellatedMesh::FromSTL("../stl/isolde/IS659/CloverGeCrystals.stl");
    auto ln2TessMesh = CADMesh::TessellatedMesh::FromSTL("../stl/isolde/IS659/CloverLN2.stl");
    //scale (SetSCale uses a double, so cannot be used to set unit of mm - use multiplier when needed (see stl files))

    //offset
    casingsTessMesh->SetOffset(G4ThreeVector(-401.63*mm, 71.647*mm, -1569.255*mm));
    fixingsTessMesh->SetOffset(G4ThreeVector(-401.63*mm, 71.647*mm, -1569.255*mm));
    dewarsTessMesh->SetOffset(G4ThreeVector(-401.63*mm, 71.647*mm, -1569.255*mm));
    crystalsTessMesh->SetOffset(G4ThreeVector(-401.63*mm, 71.647*mm, -1569.255*mm));
    ln2TessMesh->SetOffset(G4ThreeVector(-401.63*mm, 71.647*mm, -1569.255*mm));

    //Solid
    G4VSolid* casings_sol = casingsTessMesh->GetSolid();
    G4VSolid* fixings_sol = fixingsTessMesh->GetSolid();
    G4VSolid* dewars_sol = dewarsTessMesh->GetSolid();
    G4VSolid* crystals_sol = crystalsTessMesh->GetSolid();
    G4VSolid* ln2_sol = ln2TessMesh->GetSolid();

    // Logical Volume
    G4String name="/IS659Clovers";
    G4RotationMatrix rotation = G4RotationMatrix();

    if(0 != spin) rotation.rotateZ(spin);
    rotation.rotateY(phi);
    rotation.rotateX(theta);


    G4ThreeVector translation(0., 0., rho);
    if(0 != spin) translation.rotateZ(spin);
    translation.rotateY(phi);
    translation.rotateX(theta);

    G4Transform3D transformation(rotation, translation);

    // Capsule
    casings_sol = casingsTessMesh->GetSolid();
    casings_log = new G4LogicalVolume(casings_sol, Al_mat, name+"/casings_log");
    casings_log->SetVisAttributes(frame_vis_att);
    casings_phys = new G4PVPlacement(transformation, name+"/casings_phys",casings_log, mother, false, 0);

    fixings_sol = fixingsTessMesh->GetSolid();
    fixings_log = new G4LogicalVolume(fixings_sol, Steel_mat, name+"/fixings_log");
    fixings_log->SetVisAttributes(frame_vis_att);
    fixings_phys = new G4PVPlacement(transformation, name+"/fixings_phys",fixings_log, mother, false, 0);

    dewars_sol = dewarsTessMesh->GetSolid();
    dewars_log = new G4LogicalVolume(dewars_sol, Steel_mat, name+"/dewars_log");
    dewars_log->SetVisAttributes(frame_vis_att);
    dewars_phys = new G4PVPlacement(transformation, name+"/dewars_phys",dewars_log, mother, false, 0);

    crystals_sol = crystalsTessMesh->GetSolid();
    crystals_log = new G4LogicalVolume(crystals_sol, Ge_mat, name+"/crystals_log");
    crystals_log->SetVisAttributes(frame_vis_att);
    crystals_phys = new G4PVPlacement(transformation, name+"/crystals_phys",crystals_log, mother, false, 0);

    ln2_sol = ln2TessMesh->GetSolid();
    ln2_log = new G4LogicalVolume(ln2_sol, ln2_mat, name+"/ln2_log");
    ln2_log->SetVisAttributes(frame_vis_att);
    ln2_phys = new G4PVPlacement(transformation, name+"/ln2_phys",ln2_log, mother, false, 0);

    return(mother);

}
