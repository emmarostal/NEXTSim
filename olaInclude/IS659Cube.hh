//
// Created by jeppe on 10/30/24.
//

#ifndef NEXTSIM_IS659CUBE_HH
#define NEXTSIM_IS659CUBE_HH


// Include-files for detector construction
#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Polycone.hh"
#include "G4Polyhedra.hh"
#include "G4Trap.hh"
#include "G4Sphere.hh"
#include "G4IntersectionSolid.hh"
#include "G4SubtractionSolid.hh"
#include "G4UnionSolid.hh"
#include "G4DisplacedSolid.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4VSolid.hh"
#include "G4ThreeVector.hh"
#include "G4RotationMatrix.hh"
#include "G4Transform3D.hh"
#include "G4PVPlacement.hh"
#include "CloverSingleDetector.hh"

// Include-files for detector readout
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "CADMesh.hh"

class IS659Cube : public G4VUserDetectorConstruction
{
public:
    IS659Cube(G4VPhysicalVolume* p_mother, G4double p_rho, G4double p_theta, G4double p_phi, G4double p_spin);
    ~IS659Cube();

    G4VPhysicalVolume* Construct();

private:
    // Crystals defined by the CloverSingleDetector class

    // Solid, Physical, Logical and CADMesh  volumes of the Capsules and Carbon window
    //
    G4VSolid* ladderAndEars_sol, *mount_sol, *betas_sol, *W1s_sol;

    Mesh* ladderAndEars_mesh, *mount_mesh, *betas_mesh, *W1s_mesh;

    G4VPhysicalVolume* ladderAndEars_phys, *mount_phys, *betas_phys, *W1s_phys;

    G4LogicalVolume* ladderAndEars_log, *mount_log, *betas_log, *W1s_log;

    const G4VisAttributes* ladderAndEars_vis_att, *mount_vis_att, *betas_vis_att, *W1s_vis_att;

    // Physical and Logical volumes of the environnement
    //
    G4VPhysicalVolume* det_env;
    G4VPhysicalVolume* mother;

    G4LogicalVolume* det_env_log;
    G4LogicalVolume* mother_log;

    // Position and Orientation
    //
    G4double rho;
    G4double phi;
    G4double theta;
    G4double spin;
};
#endif //NEXTSIM_IS659CUBE_HH
