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
#include "IS659VandleFrame.hh"
#include "G4VisAttributes.hh"
#include "G4SystemOfUnits.hh"
#include "G4NistManager.hh"
#include "CADMesh.hh"

#ifdef Error
#undef Error
#endif


using namespace std;



IS659VandleFrame::IS659VandleFrame(G4VPhysicalVolume* p_mother, G4double p_rho, G4double p_theta, G4double p_phi, G4double p_spin)
        :mother(p_mother), rho(p_rho), theta(p_theta), phi(p_phi), spin(p_spin)
{
    //G4cout	<<"\nClover Quad (Bucharest) DETECTOR#######################\n"	<<flush
    //	<<"\nRho =\t\t"		<<rho/mm	<< " mm"	<<flush
    //	<<"\nTheta =\t\t"	<<theta/deg	<< " deg" 	<<flush
    //	<<"\nPhi =\t\t"		<<phi/deg	<< " deg"       <<flush
    //	<<"\nSpin =\t\t"	<<spin/deg	<< " deg"       <<flush
    //	<<"\nCloverNb =\t"	<<cl_nb 			<<G4endl;
}

IS659VandleFrame::~IS659VandleFrame()
{;}


G4VPhysicalVolume* IS659VandleFrame::Construct()
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
    tapeBoxVisAtt->SetForceSolid(true);
    frame_vis_att       = tapeBoxVisAtt;

    //tesselated mesh
    auto CapsuleTessMesh = CADMesh::TessellatedMesh::FromSTL("../stl/isolde/IS659/vandleFrameASCII.stl");

    //scale (SetSCale uses a double, so cannot be used to set unit of mm - use multiplier when needed (see stl files))

    //offset
    CapsuleTessMesh->SetOffset(G4ThreeVector(-401.63*mm, 71.647*mm, -1569.255*mm));
    //CapsuleTessMesh->SetOffset(G4ThreeVector(0*mm, 0*mm, 0*mm));

    //Solid
    auto Capsule_sol = CapsuleTessMesh->GetSolid();

    // Logical Volume
    G4String name="/IS659VandleFrame";
    frame_log		= new G4LogicalVolume(Capsule_sol       , Al_mat, name+"/Capsule_log"           );
    frame_log		->SetVisAttributes(frame_vis_att);

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
    frame_phys       = new G4PVPlacement(transformation, name+"/Capsule", frame_log, mother, false, 0);


    return(mother);

}