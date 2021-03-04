#include "TrackerSD.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "Analysis.hh"
#include "G4SystemOfUnits.hh"
#include "PrimaryGeneratorAction.hh"
#include <cmath>
#include <math.h>

TrackerSD::TrackerSD(const G4String &name,
                     const G4String &hitsCollectionName)
    : G4VSensitiveDetector(name),
      fHitsCollection(NULL)
{
  collectionName.insert(hitsCollectionName);
}

TrackerSD::~TrackerSD()
{
}

void TrackerSD::Initialize(G4HCofThisEvent *hce)
{
  fHitsCollection = new TrackerHitsCollection(SensitiveDetectorName, collectionName[0]);
  G4int hcID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
  hce->AddHitsCollection(hcID, fHitsCollection);
}

G4bool TrackerSD::ProcessHits(G4Step *aStep,
                              G4TouchableHistory *)
{

  G4Track *track = aStep->GetTrack();
  TrackerHit *newHit = new TrackerHit();

  if (track->GetDefinition()->GetParticleName() != "gamma")
    return false;

  const G4DynamicParticle *dynParticle = track->GetDynamicParticle();

  newHit->SetKineticEnergy(dynParticle->GetKineticEnergy());
  newHit->SetMomentumDirection(aStep->GetTrack()->GetMomentumDirection());
  newHit->SetPos(aStep->GetPostStepPoint()->GetPosition());
  newHit->SetEdep(aStep->GetTotalEnergyDeposit());
  newHit->SetTrackID(track->GetTrackID());

  fHitsCollection->insert(newHit);
  return true;
}

void TrackerSD::EndOfEvent(G4HCofThisEvent *)
{
  G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();

  G4int nofHits = fHitsCollection->entries();
  if (nofHits > 0)
  {
    for (G4int i = 0; i < nofHits; i++)
    {
          analysisManager->FillH1(1, (*fHitsCollection)[i]->GetMomentumDirection().theta());
          analysisManager->FillH1(2, (*fHitsCollection)[i]->GetKineticEnergy());
    }
  }
}
