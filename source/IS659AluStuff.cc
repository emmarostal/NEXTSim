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
#include "IS659AluStuff.hh"
#include "G4VisAttributes.hh"
#include "G4SystemOfUnits.hh"
#include "G4NistManager.hh"
#include "CADMesh.hh"

#ifdef Error
#undef Error
#endif


using namespace std;


//lazily build everything aluminum in this class

IS659AluStuff::IS659AluStuff(G4VPhysicalVolume* p_mother, G4double p_rho, G4double p_theta, G4double p_phi, G4double p_spin)
        :mother(p_mother), rho(p_rho), theta(p_theta), phi(p_phi), spin(p_spin)
{
    //G4cout	<<"\nClover Quad (Bucharest) DETECTOR#######################\n"	<<flush
    //	<<"\nRho =\t\t"		<<rho/mm	<< " mm"	<<flush
    //	<<"\nTheta =\t\t"	<<theta/deg	<< " deg" 	<<flush
    //	<<"\nPhi =\t\t"		<<phi/deg	<< " deg"       <<flush
    //	<<"\nSpin =\t\t"	<<spin/deg	<< " deg"       <<flush
    //	<<"\nCloverNb =\t"	<<cl_nb 			<<G4endl;
}

IS659AluStuff::~IS659AluStuff()
{;}


G4VPhysicalVolume* IS659AluStuff::Construct()
{
    // Material
    //
    G4NistManager* NISTmgr = G4NistManager::Instance();

    G4Material* Vacuum          = NISTmgr->FindOrBuildMaterial("G4_Galactic");
    G4Material* Air             = NISTmgr->FindOrBuildMaterial("G4_AIR");
    G4Material* Al_mat          = NISTmgr->FindOrBuildMaterial("G4_Al");


    // Visualisation
    //
    G4VisAttributes* tapeBoxVisAtt = new G4VisAttributes( G4Colour(0.3,0.3,0.3));
    tapeBoxVisAtt->SetForceAuxEdgeVisible(true);// Can see outline when drawn with lines
    //tapeBoxVisAtt->SetForceSolid(true);
    frame_vis_att       = tapeBoxVisAtt;

    //tesselated mesh
    auto polygonTessMesh = CADMesh::TessellatedMesh::FromSTL("../stl/isolde/IS659/polygonFixed.stl");
    auto polygonFrameTessMesh = CADMesh::TessellatedMesh::FromSTL("../stl/isolde/IS659/polygonStandFixed.stl");
    auto feedthroughTessMesh = CADMesh::TessellatedMesh::FromSTL("../stl/isolde/IS659/tubesAndFeedthrough.stl");
    auto tapeTessMesh = CADMesh::TessellatedMesh::FromSTL("../stl/isolde/IS659/tapeStation.stl");
    auto chamberTessMesh = CADMesh::TessellatedMesh::FromSTL("../stl/isolde/IS659/chamber.stl");
    auto facelidTessMesh = CADMesh::TessellatedMesh::FromSTL("../stl/isolde/IS659/faceLid.stl");
    auto beamlineTessMesh = CADMesh::TessellatedMesh::FromSTL("../stl/isolde/IS659/beamLine.stl");

    //scale (SetSCale uses a double, so cannot be used to set unit of mm - use multiplier when needed (see stl files))

    //offset
    polygonTessMesh->SetOffset(G4ThreeVector(-401.63*mm, 71.647*mm, -1569.255*mm));
    polygonFrameTessMesh->SetOffset(G4ThreeVector(-401.63*mm, 71.647*mm, -1569.255*mm));
    feedthroughTessMesh->SetOffset(G4ThreeVector(-401.63*mm, 71.647*mm, -1569.255*mm));
    tapeTessMesh->SetOffset(G4ThreeVector(-401.63*mm, 71.647*mm, -1569.255*mm));
    chamberTessMesh->SetOffset(G4ThreeVector(-401.63*mm, 71.647*mm, -1569.255*mm));
    facelidTessMesh->SetOffset(G4ThreeVector(-401.63*mm, 71.647*mm, -1569.255*mm));
    beamlineTessMesh->SetOffset(G4ThreeVector(-401.63*mm, 71.647*mm, -1569.255*mm));

    //Solid
    polygon_sol = polygonTessMesh->GetSolid();
    frame_sol = polygonFrameTessMesh->GetSolid();
    feedthrough_sol = feedthroughTessMesh->GetSolid();
    tape_sol = tapeTessMesh->GetSolid();
    chamber_sol = chamberTessMesh->GetSolid();
    facelid_sol = facelidTessMesh->GetSolid();
    beamline_sol = beamlineTessMesh->GetSolid();

    // Logical Volume
    G4String name="/IS659PolygonFrame";
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
    frame_log		= new G4LogicalVolume(frame_sol       , Al_mat, name+"/frame_log"           );
    frame_log		->SetVisAttributes(frame_vis_att);
    frame_phys       = new G4PVPlacement(transformation, name+"/frame", frame_log, mother, false, 0);

    polygon_log = new G4LogicalVolume(polygon_sol, Al_mat, name+"/polygon_log");
    polygon_log->SetVisAttributes(frame_vis_att);
    polygon_phys = new G4PVPlacement(transformation, name+"/polygon", polygon_log, mother, false, 0);

    feedthrough_log = new G4LogicalVolume(feedthrough_sol, Al_mat, name+"/feedthrough_log");
    feedthrough_log->SetVisAttributes(frame_vis_att);
    feedthrough_phys = new G4PVPlacement(transformation, name+"/feedthrough", feedthrough_log, mother, false, 0);

    tape_log = new G4LogicalVolume(tape_sol, Al_mat, name+"/tape_log");
    tape_log->SetVisAttributes(frame_vis_att);
    tape_phys = new G4PVPlacement(transformation, name+"/tape", tape_log, mother, false, 0);

    chamber_log = new G4LogicalVolume(chamber_sol, Al_mat, name+"/chamber_log");
    chamber_log->SetVisAttributes(frame_vis_att);
    chamber_phys = new G4PVPlacement(transformation, name+"/chamber", chamber_log, mother, false, 0);

    beamline_log = new G4LogicalVolume(beamline_sol, Al_mat, name+"/beamline_log");
    beamline_log->SetVisAttributes(frame_vis_att);
    beamline_phys = new G4PVPlacement(transformation, name+"/beamline", beamline_log, mother, false, 0);

    facelid_log = new G4LogicalVolume(facelid_sol, Al_mat, name+"/facelid_log");
    facelid_log->SetVisAttributes(frame_vis_att);
    facelid_phys = new G4PVPlacement(transformation, name+"/facelid", facelid_log, mother, false, 0);


    return(mother);

}
