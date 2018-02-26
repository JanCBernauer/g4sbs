#ifndef __G4SBSHArmBuilder_hh
#define __G4SBSHArmBuilder_hh

#include "G4SBSComponent.hh"
#include "globals.hh"
#include "G4ThreeVector.hh"
#include "G4RotationMatrix.hh"

class G4SBSHArmBuilder: public G4SBSComponent {
public:
  G4SBSHArmBuilder(G4SBSDetectorConstruction *);
  ~G4SBSHArmBuilder();

  void BuildComponent(G4LogicalVolume *);

  void Set48D48Ang(double a){ f48D48ang = a; }
  void SetHCALDist(double a){ fHCALdist= a;   }
  void SetHCALVOffset(double a){ fHCALvertical_offset = a; }
  void SetHCALHOffset(double a){ fHCALhorizontal_offset = a; }
  void Set48D48Dist(double a){ f48D48dist = a; }
  void SetRICHdist( double d ){ fRICHdist = d; } //Set RICH detector distance
  void SetFieldClampConfig48D48( int option ){ f48D48_fieldclamp_config = option; }
  void SetTrackerPitch(double a){ fSBS_tracker_pitch = a; }
  void SetTrackerDist(double d){ fSBS_tracker_dist = d; }
  void SetSBSSieve(bool a){fBuildSBSSieve = a;};
  void SetRICHgas( G4String s ){ fRICHgas = s; }
  void SetRICH_use_aerogel( G4bool b ){ fRICH_use_aerogel = b; }
  
  void Make48D48(G4LogicalVolume*, double);
  void MakeSBSFieldClamps(G4LogicalVolume*);
  void MakeHCAL(G4LogicalVolume*, G4double);
  void MakeHCALV2(G4LogicalVolume*, G4double);
  void MakeCDET(G4LogicalVolume*, G4double, G4double);
  void MakeFPP(G4LogicalVolume*, G4RotationMatrix*, G4ThreeVector );
  void MakeRICH(G4LogicalVolume *);
  void MakeRICH_new(G4LogicalVolume *);
  void MakeTracker(G4LogicalVolume *);
  void MakeGEpFPP(G4LogicalVolume *);
  void MakeTracker_A1n(G4LogicalVolume *);
  void MakeElectronModeSBS(G4LogicalVolume *);
  void MakeLACModule(G4LogicalVolume *);
  void MakeSBSSieveSlit(G4LogicalVolume *);
  
  double f48D48ang;
  double f48D48dist;
  int f48D48_fieldclamp_config; //Configuration of field clamp. There could be several of these.
  double fHCALdist;
  double fHCALvertical_offset;  // Vertical offset (from center) of HCAL
  double fHCALhorizontal_offset; // Horizontal offset (from SBS center line) of HCAL (by convention, +X is toward smaller angle)
  double fRICHdist; //Distance from target to RICH entry window (in horizontal plane)
  double fSBS_tracker_pitch; //SBS tracker pitch angle for electron mode
  double fSBS_tracker_dist; 
  
  // Useful constants
  double f48D48depth;
  double f48D48height;
  double f48D48width;

  bool fUseLocalField;
  
  double fFieldStrength;
  
  bool fBuildSBSSieve;

  G4String fRICHgas; //String defining
  G4bool   fRICH_use_aerogel; // Flag to use or not use aerogel
  
private:

};

#endif//__G4SBSHArmBuilder_hh
