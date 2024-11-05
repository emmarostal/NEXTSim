
/************************************************************************
 * \file CloverQuadDetector.hh
 *
 * \class CloverQuadDetector
 * \brief Design of a HPGe crystal of a clover detector (KU Leuven)
 *
 * \author csotty@gmail.com
 *
 *************************************************************************/

#ifndef IS659AluStuff_H
#define IS659AluStuff_H 1


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

class IS659AluStuff : public G4VUserDetectorConstruction
{
public:
    IS659AluStuff(G4VPhysicalVolume* p_mother, G4double p_rho, G4double p_theta, G4double p_phi, G4double p_spin);
    ~IS659AluStuff();

    G4VPhysicalVolume* Construct();

private:
    G4VSolid *frame_sol, *polygon_sol, *tape_sol, *feedthrough_sol, *chamber_sol, *beamline_sol, *facelid_sol;

    Mesh* frame_mesh, *polygon_mesh, *tape_mesh, *feedthrough_mesh, *chamber_mesh, *beamline_mesh, *facelid_mesh;

    G4VPhysicalVolume* frame_phys, *polygon_phys, *tape_phys, *feedthrough_phys, *chamber_phys, *beamline_phys, *facelid_phys;

    G4LogicalVolume* frame_log, *polygon_log, *tape_log, *feedthrough_log, *chamber_log, *beamline_log, *facelid_log;
    const G4VisAttributes* frame_vis_att, *polygon_vis_att, *tape_vis_att, *feedthrough_vis_att, *chamber_vis_att, *beamline_vis_att;

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
