#ifndef TrackerSD_h
#define TrackerSD_h 1

#include "G4VSensitiveDetector.hh"
#include "TrackerHit.hh"
#include <vector>

class G4Step;
class G4HCofThisEvent;

class TrackerSD : public G4VSensitiveDetector
{
  public:
    TrackerSD(const G4String& name,
                const G4String& hitsCollectionName);
    virtual ~TrackerSD();

    // methods from base class
    virtual void   Initialize(G4HCofThisEvent* hitCollection);
    virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory* history);
    virtual void   EndOfEvent(G4HCofThisEvent* hitCollection);

  private:
    TrackerHitsCollection* fHitsCollection;
    G4int fAtmSlice;
};

#endif
