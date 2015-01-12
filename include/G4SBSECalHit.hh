#ifndef G4SBSECalHit_h 
#define G4SBSECalHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4LogicalVolume.hh"

class G4SBSECalHit : public G4VHit
{
public:
  G4SBSECalHit();
  ~G4SBSECalHit();
  
  G4SBSECalHit( const G4SBSECalHit &hit );
  const G4SBSECalHit & operator=( const G4SBSECalHit &hit );
  
  G4int operator==(const G4SBSECalHit &hit ) const;

  inline void * operator new(size_t);
  inline void operator delete(void *aHit);
  
  virtual void Draw();
  virtual void Print();

  //Utility functions to map rows and columns to PMT numbers
  G4int calc_row( G4int PMT );
  G4int calc_col( G4int PMT );

private:
  
  //What are the relevant properties of a ECal hit?
  //    1) Timing
  //    2) # of photoelectrons
  //    3) Energy deposited by primary particle
  //    4) What else? Computationally hard to keep track of certain 
  //       quantities because we expect ~10^4 - 10^5 optical photons to be 
  //       created during an EM shower.

  G4int fTrackID;              //track number of current track
  //G4int fMotherID;             //track number of mother of current track
  //G4int fTrackPID;             //particle ID of current track
  //G4int fMotherPID;            //particle ID of current track
  G4ThreeVector fpos;          //position of the step (global)
  //G4ThreeVector fLpos;         //position of the step  (local to the volume)
  //G4ThreeVector fdirection;    //momentum direction of the step
  //G4ThreeVector fvertex;       //Primary vertex of the current track
  //G4ThreeVector fMothervertex; //Primary vertex of the track's mother
  //G4ThreeVector fvertexdirection; //momentum direction at the primary vertex;
  //G4ThreeVector fMothervertexdirection; //Mother particle momentum direction
  G4double fedep;              //Energy deposit
  G4double fdx;                //Step length
  G4double fenergy;            //optical photon energy in this step
  G4double ftime;              //Global time since start of event
  G4int fPMTnumber;            //PMT number;
  G4int frownumber;            //PMT row number
  G4int fcolnumber;            //PMT column number
  //G4int foriginvol;            //Volume in which the track of this optical photon originated (1=Aerogel, 2=RICHbox, 3=lucite, 0=other)

  //Need to store a pointer to logical volume in order to retrieve quantum efficiency info later:
  G4LogicalVolume *fvolume_log;

public:
  //Get/set methods for sensitive detector:
  
  //Track IDs:
  inline void SetTrackID( G4int tid ){ fTrackID = tid; }
  inline G4int GetTrackID() const { return fTrackID; }
  
  //inline void SetMotherID( G4int mid ){ fMotherID = mid; }
  //inline G4int GetMotherID() const { return fMotherID; }
  
  //Particle IDs:
  // inline void SetTrackPID( G4int tid ){ fTrackPID = tid; }
  // inline G4int GetTrackPID() const { return fTrackPID; }
  
  // inline void SetMotherPID( G4int mid ){ fMotherPID = mid; }
  // inline G4int GetMotherPID() const { return fMotherPID; }

  //Track positions and vertices:
  inline void SetPos( G4ThreeVector x ){ fpos = x; }
  inline G4ThreeVector GetPos() const { return fpos; }

  // inline void SetLPos( G4ThreeVector x ){ fLpos = x; }
  // inline G4ThreeVector GetLPos() const { return fLpos; }
  
  // inline void SetDirection( G4ThreeVector n ){ fdirection = n.unit(); }
  // inline G4ThreeVector GetDirection() const { return fdirection; }

  // inline void SetVertex( G4ThreeVector v ){ fvertex = v; }
  // inline G4ThreeVector GetVertex() const { return fvertex; }

  // inline void SetVertexDirection( G4ThreeVector n ) { fvertexdirection = n.unit(); }
  // inline G4ThreeVector GetVertexDirection() const { return fvertexdirection; }

  // inline void SetMotherVertex( G4ThreeVector v ){ fMothervertex = v; }
  // inline G4ThreeVector GetMotherVertex() const { return fMothervertex; }

  // inline void SetMotherVertexDirection( G4ThreeVector n ) { fMothervertexdirection = n.unit(); }
  // inline G4ThreeVector GetMotherVertexDirection() const { return fMothervertexdirection; }

  //Step physical properties (energy deposit, energy, time, step length):
  inline void SetEdep( G4double dE ){ fedep = dE; }
  inline G4double GetEdep() const { return fedep; }
  
  inline void Setdx( G4double d ){ fdx = d; }
  inline G4double Getdx() const { return fdx; }
  
  inline void Setenergy( G4double E ){ fenergy = E; }
  inline G4double Getenergy() const { return fenergy; }
  
  inline void SetTime( G4double t ){ ftime = t; }
  inline G4double GetTime() const { return ftime; }

  //Digital information regarding PMT (PMT number, row number, column number):
  inline void SetPMTnumber( G4int n ){ fPMTnumber = n; }
  inline G4int GetPMTnumber() const { return fPMTnumber; }

  inline void Setrownumber( G4int i ){ frownumber = i; }
  inline G4int Getrownumber() const { return frownumber; }

  inline void Setcolnumber( G4int i ){ fcolnumber = i; }
  inline G4int Getcolnumber() const { return fcolnumber; }
  
  // inline void SetOriginVol( G4int i ){ foriginvol = i; }
  // inline G4int GetOriginVol() const { return foriginvol; }

  inline void SetLogicalVolume( G4LogicalVolume *v ){  fvolume_log = v; }
  inline G4LogicalVolume *GetLogicalVolume() { return fvolume_log; }
};

typedef G4THitsCollection<G4SBSECalHit> G4SBSECalHitsCollection;

extern G4Allocator<G4SBSECalHit> *G4SBSECalHitAllocator;

inline void *G4SBSECalHit::operator new(size_t)
{
  if( !G4SBSECalHitAllocator )  G4SBSECalHitAllocator = new G4Allocator<G4SBSECalHit>;
  return (void *) G4SBSECalHitAllocator->MallocSingle();
}

inline void G4SBSECalHit::operator delete(void *aHit)
{
  G4SBSECalHitAllocator->FreeSingle( (G4SBSECalHit*) aHit );
}

#endif
