#ifndef TrackerHit_h
#define TrackerHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "tls.hh"

// Tracker hit class
// It defines data members to store the , chamberNb, energy deposit,
// and position of charged particles in a selected volume:
// - fTrackID, fEdep, fPos

class TrackerHit : public G4VHit
{
public:
  TrackerHit();
  TrackerHit(const TrackerHit &);
  virtual ~TrackerHit();

  // operators
  const TrackerHit &operator=(const TrackerHit &);
  G4int operator==(const TrackerHit &) const;

  inline void *operator new(size_t);
  inline void operator delete(void *);

  // Set methods
  void SetTrackID(G4int track) { fTrackID = track; };
  void SetEdep(G4double de) { fEdep = de; };
  void AddEdep(G4double de) { fEdep += de; }
  void SetPos(G4ThreeVector xyz) { fPos = xyz; };
  void SetMomentumDirection(G4ThreeVector p) { fP = p; };
  void setSecondaryNumber(G4int n) { fn = n; };
  void SetKineticEnergy(G4double ke) { fKe = ke; };
  void SetParticleName(G4String na) { fNa = na; };

  // Get methods
  G4int GetTrackID() const { return fTrackID; };
  G4double GetEdep() const { return fEdep; };
  G4ThreeVector GetPos() const { return fPos; };
  G4ThreeVector GetMomentumDirection() const { return fP; };
  G4int getSecondaryNumber() const { return fn; };
  G4double GetKineticEnergy() const { return fKe; };
  G4String GetParticleName() const { return fNa; };

private:
  G4int fTrackID;
  G4double fEdep;
  G4ThreeVector fP;
  G4ThreeVector fPos;
  G4int fn;
  G4double fKe;
  G4String fNa;
};

typedef G4THitsCollection<TrackerHit> TrackerHitsCollection;

extern G4ThreadLocal G4Allocator<TrackerHit> *TrackerHitAllocator;

inline void *TrackerHit::operator new(size_t)
{
  if (!TrackerHitAllocator)
    TrackerHitAllocator = new G4Allocator<TrackerHit>;
  return (void *)TrackerHitAllocator->MallocSingle();
}

inline void TrackerHit::operator delete(void *hit)
{
  TrackerHitAllocator->FreeSingle((TrackerHit *)hit);
}

#endif
