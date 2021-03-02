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

TrackerSD::TrackerSD(const G4String& name,
                     const G4String& hitsCollectionName)
 : G4VSensitiveDetector(name),
   fHitsCollection(NULL) {
  collectionName.insert(hitsCollectionName);
}

TrackerSD::~TrackerSD() {
}

void TrackerSD::Initialize(G4HCofThisEvent* hce) {
  fHitsCollection
    = new TrackerHitsCollection(SensitiveDetectorName, collectionName[0]);
  G4int hcID
    = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
  hce->AddHitsCollection( hcID, fHitsCollection );
}

G4bool TrackerSD::ProcessHits(G4Step* aStep,
                                     G4TouchableHistory*) {

  // G4Track* track = aStep->GetTrack();


  //G4double theta = acos(-p.z());

  // we are only sensitive to photons. Track no other particles.
  //std::cout << aStep->GetTrack()->GetDefinition()->GetParticleName();
  //if (aStep->GetTrack()->GetDefinition()->GetParticleName() != "gamma") return false;

  TrackerHit* newHit = new TrackerHit();
  const G4DynamicParticle* dynParticle = aStep->GetTrack()->GetDynamicParticle();

  //const G4DynamicParticle* dynParticle = track->GetDynamicParticle();

  newHit->SetKineticEnergy(dynParticle->GetKineticEnergy());


  //newHit->SetTrackID  (track->GetTrackID());
  newHit->SetChamberNb(aStep->GetPreStepPoint()->GetTouchableHandle()
                                               ->GetCopyNumber());
  //newHit->SetEdep(aStep->GetTotalEnergyDeposit());
  newHit->SetMomentumDirection(aStep->GetTrack()->GetMomentumDirection());
  newHit->SetPos (aStep->GetPostStepPoint()->GetPosition());

  newHit->SetParticleName(aStep->GetTrack()->GetDefinition()->GetParticleName());

  fHitsCollection->insert(newHit);

  return true;

}

void TrackerSD::EndOfEvent(G4HCofThisEvent*)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

  G4int nofHits = fHitsCollection->entries();
  if ( nofHits > 0 ) {
    for ( G4int i=0; i<nofHits; i++ ) {

      int nb = (*fHitsCollection)[i]->GetChamberNb();

      /*if ((*fHitsCollection)[i]->GetParticleName() == "e-") { // only downward electrons
        if ((*fHitsCollection)[i]->GetMomentumDirection().z() < 0) {
        //analysisManager->FillH1(nb + 1500,(*fHitsCollection)[i]->GetKineticEnergy());
        //analysisManager->FillH1(nb + 2000,(*fHitsCollection)[i]->GetMomentumDirection().theta());

      }
    }*/


      if ((*fHitsCollection)[i]->GetParticleName() == "gamma") {
        if ((*fHitsCollection)[i]->GetMomentumDirection().z() > 0) { // only DOWN
        double y = (*fHitsCollection)[i]->GetMomentumDirection().y();
        double x = (*fHitsCollection)[i]->GetMomentumDirection().x();

        double xp = (*fHitsCollection)[i]->GetPos().x();
        double yp = (*fHitsCollection)[i]->GetPos().y();


        analysisManager->FillH1(nb,(*fHitsCollection)[i]->GetMomentumDirection().theta());
        G4double phi = std::atan2(y,x);  // phi in [-pi, +pi[
        if (phi < 0.) phi = phi + 2*CLHEP::pi;                          // phi in [o, twopi[
        analysisManager->FillH1(nb + 500, phi);
        analysisManager->FillH1(nb + 1000,(*fHitsCollection)[i]->GetKineticEnergy());

        /*if (sqrt(pow(xp,2)+pow(yp,2)) <= 5*km) {
        double ke = (*fHitsCollection)[i]->GetKineticEnergy();
        analysisManager->FillH1(nb + 2500,((*fHitsCollection)[i]->GetMomentumDirection().x())*ke);
        analysisManager->FillH1(nb + 3000,((*fHitsCollection)[i]->GetMomentumDirection().y())*ke);
        analysisManager->FillH1(nb + 3500,((*fHitsCollection)[i]->GetMomentumDirection().z())*ke);*/

        }
}
        //if ((*fHitsCollection)[i]->GetMomentumDirection().z() < 0) {
          //analysisManager->FillH2(nb, x, y, 1.0); // only downward photons, no backscatter allowed
        //}
      }
    }
  }
      //std::cout << std::to_string(nb+1);

    //for ( G4int i=0; i<nofHits; i++ ) (*fHitsCollection)[i]->Print();
     //G4double eventTotalEnergy = 0.0;
     //for ( G4int i=0; i<nofHits; i++) {
    //   eventTotalEnergy = eventTotalEnergy + (*fHitsCollection)[i]->GetEdep();
    // }
    //analysisManager->FillH1(1, eventTotalEnergy, 1.0);
    // for (G4int i=0; i<nofHits; i++) {
    //    analysisManager->FillH1(1, (*fHitsCollection)[i]->GetEdep(), 1.0);
     //}
    // don't histogram each steps energy deposit. histogram each EVENT energy deposit


