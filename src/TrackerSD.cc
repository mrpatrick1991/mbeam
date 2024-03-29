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
#include <G4Gamma.hh>
#include <G4DynamicParticle.hh>
#include "Config.hh"

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

  TrackerHit *newHit = new TrackerHit();

  newHit->SetKineticEnergy(aStep->GetTrack()->GetDynamicParticle()->GetKineticEnergy());
  newHit->SetMomentumDirection(aStep->GetTrack()->GetMomentumDirection());
  newHit->SetPos(aStep->GetPostStepPoint()->GetPosition());
  newHit->SetEdep(aStep->GetTotalEnergyDeposit());
  newHit->SetTrackID(aStep->GetTrack()->GetTrackID());
  newHit->SetParticleDef(aStep->GetTrack()->GetDefinition());
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
          if ( (*fHitsCollection)[i]->GetParticleDef() == G4Gamma::Definition()) {
            analysisManager->FillH1(1, (*fHitsCollection)[i]->GetMomentumDirection().theta());
            analysisManager->FillH1(2, (*fHitsCollection)[i]->GetKineticEnergy());
          }
    }
  }
}
