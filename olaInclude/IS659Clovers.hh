
/************************************************************************
 * \file CloverQuadDetector.hh
 *
 * \class CloverQuadDetector
 * \brief Design of a HPGe crystal of a clover detector (KU Leuven)
 *
 * \author csotty@gmail.com
 *
 *************************************************************************/

#ifndef IS659Clovers_H
#define IS659Clovers_H 1


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

#ifdef G4VIS_USE
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#endif

class IS659Clovers : public G4VUserDetectorConstruction
{
public:
    IS659Clovers(G4VPhysicalVolume* p_mother, G4double p_rho, G4double p_theta, G4double p_phi, G4double p_spin);
    ~IS659Clovers();

    G4VPhysicalVolume* Construct();

private:
    G4VSolid *casings_sol, *fixings_sol, *dewars_sol, *crystals_sol, *ln2_sol;

    Mesh* casings_mesh, *fixings_mesh, *dewars_mesh, *crystals_mesh, *ln2_mesh;

    G4VPhysicalVolume* casings_phys, *fixings_phys, *dewars_phys, *crystals_phys, *ln2_phys;

    G4LogicalVolume* casings_log, *fixings_log, *dewars_log, *crystals_log, *ln2_log;
    const G4VisAttributes* frame_vis_att;

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

#endif
