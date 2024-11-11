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
#include "IS659Cube.hh"
#include "G4VisAttributes.hh"
#include "G4SystemOfUnits.hh"
#include "G4NistManager.hh"
#include "CADMesh.hh"

#ifdef Error
#undef Error
#endif


using namespace std;



IS659Cube::IS659Cube(G4VPhysicalVolume* p_mother, G4double p_rho, G4double p_theta, G4double p_phi, G4double p_spin)
        :mother(p_mother), rho(p_rho), theta(p_theta), phi(p_phi), spin(p_spin)
{
    //G4cout	<<"\nClover Quad (Bucharest) DETECTOR#######################\n"	<<flush
    //	<<"\nRho =\t\t"		<<rho/mm	<< " mm"	<<flush
    //	<<"\nTheta =\t\t"	<<theta/deg	<< " deg" 	<<flush
    //	<<"\nPhi =\t\t"		<<phi/deg	<< " deg"       <<flush
    //	<<"\nSpin =\t\t"	<<spin/deg	<< " deg"       <<flush
    //	<<"\nCloverNb =\t"	<<cl_nb 			<<G4endl;
}

IS659Cube::~IS659Cube()
{;}


G4VPhysicalVolume* IS659Cube::Construct()
{
    // Material
    //
    G4NistManager* NISTmgr = G4NistManager::Instance();

    G4Material* Vacuum          = NISTmgr->FindOrBuildMaterial("G4_Galactic");
    G4Material* Air             = NISTmgr->FindOrBuildMaterial("G4_AIR");
    G4Material* Al_mat          = NISTmgr->FindOrBuildMaterial("G4_Al");
    G4Material* print3d_mat     = NISTmgr->FindOrBuildMaterial("G4_POLYPROPYLENE");
    /*G4Element* C =NISTmgr->FindOrBuildElement("C"); // Carbon
    G4Element* H = NISTmgr->FindOrBuildElement("H"); // Hydrogen
    G4Element* N = NISTmgr->FindOrBuildElement("N"); // Nitrogen
    G4Element* O = NISTmgr->FindOrBuildElement("O"); // Oxygen

    G4Material* FR4_mat = new G4Material("C25H27N5O3", 1.85 * g/cm3, 4);
    FR4_mat->AddElement(C, 25);
    FR4_mat->AddElement(H, 27);
    FR4_mat->AddElement(N, 5);
    FR4_mat->AddElement(O, 3);
    G4Material* scint_mat = new G4Material("C9H10", 1.032 * g/cm3, 4);
    scint_mat->AddElement(C, 9);
    scint_mat->AddElement(H, 10);*/
    //this does not work because some physics package uses properties which are only set for G4 materials? Or I don't know. But I approximate the material instead.
    G4Material* FR4_mat = NISTmgr->BuildMaterialWithNewDensity("FR4", "G4_NYLON-8062", 1.85 * g/cm3);
    /*G4cout << "FR4 density: " << FR4_mat->GetDensity() / (g / cm3) << G4endl;
    G4cout << "FR4 mats" << G4endl;
    auto vec = FR4_mat->GetElementVector();
    for(int i = 0; i < vec->size(); i++){
        G4cout << vec->at(i)->GetName() << " " << vec->at(i)->GetN() << G4endl;
    }*/
    G4Material* scint_mat = NISTmgr->BuildMaterialWithNewDensity("scintillator", "G4_POLYPROPYLENE", 1.032 * g/cm3);

    // Visualisation
    //
    G4VisAttributes* tapeBoxVisAtt = new G4VisAttributes( G4Colour(0.3,0.3,0.3));
    tapeBoxVisAtt->SetForceAuxEdgeVisible(true);// Can see outline when drawn with lines
    tapeBoxVisAtt->SetForceSolid(true);
    mount_vis_att       = tapeBoxVisAtt;
    ladderAndEars_vis_att = tapeBoxVisAtt;
    betas_vis_att = tapeBoxVisAtt;
    W1s_vis_att = tapeBoxVisAtt;

    //tesselated mesh
    auto laddersAndEarsTessMesh = CADMesh::TessellatedMesh::FromSTL("../stl/isolde/IS659/ladderAndEars.stl");
    auto mountTessMesh = CADMesh::TessellatedMesh::FromSTL("../stl/isolde/IS659/detectorCube.stl");
    auto betasTessMesh = CADMesh::TessellatedMesh::FromSTL("../stl/isolde/IS659/betaPlastics.stl");
    auto W1sTessMesh = CADMesh::TessellatedMesh::FromSTL("../stl/isolde/IS659/W1PCBs.stl");


    //scale (SetSCale uses a double, so cannot be used to set unit of mm - use multiplier when needed (see stl files))

    //offset
    laddersAndEarsTessMesh->SetOffset(G4ThreeVector(-401.63*mm, 71.647*mm, -1569.255*mm));
    mountTessMesh->SetOffset(G4ThreeVector(-401.63*mm, 71.647*mm, -1569.255*mm));
    betasTessMesh->SetOffset(G4ThreeVector(-401.63*mm, 71.647*mm, -1569.255*mm));
    W1sTessMesh->SetOffset(G4ThreeVector(-401.63*mm, 71.647*mm, -1569.255*mm));

    //Solid
    mount_sol = mountTessMesh->GetSolid();
    ladderAndEars_sol = laddersAndEarsTessMesh->GetSolid();
    betas_sol = betasTessMesh->GetSolid();
    W1s_sol = W1sTessMesh->GetSolid();

    // Logical Volume
    G4String name="/IS659Cube";
    mount_log		= new G4LogicalVolume(mount_sol       , print3d_mat, name+"/mount_log"           );
    mount_log		->SetVisAttributes(mount_vis_att);

    ladderAndEars_log = new G4LogicalVolume(ladderAndEars_sol, Al_mat, name+"/ladderAndEars_log");
    ladderAndEars_log->SetVisAttributes(ladderAndEars_vis_att);

    betas_log = new G4LogicalVolume(betas_sol, scint_mat, name+"/betas_log");
    betas_log->SetVisAttributes(betas_vis_att);

    W1s_log = new G4LogicalVolume(W1s_sol, FR4_mat, name+"/W1s_log");
    W1s_log->SetVisAttributes(W1s_vis_att);

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
    mount_phys       = new G4PVPlacement(transformation, name+"/mount", mount_log, mother, false, 0);
    ladderAndEars_phys = new G4PVPlacement(transformation, name+"/ladderAndEars", ladderAndEars_log, mother, false, 0);
    betas_phys = new G4PVPlacement(transformation, name+"/betas", betas_log, mother, false, 0);
    W1s_phys = new G4PVPlacement(transformation, name+"/W1s", W1s_log, mother, false, 0);


    return(mother);

}
