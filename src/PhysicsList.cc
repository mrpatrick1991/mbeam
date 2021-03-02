#include "PhysicsList.hh"
#include "G4OpticalPhoton.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"

PhysicsList::PhysicsList() : G4VModularPhysicsList() {
}

PhysicsList::~PhysicsList(){
}

void PhysicsList::ConstructParticle() {
  G4VModularPhysicsList::ConstructParticle();
}

void PhysicsList::ConstructProcess() {
  G4VModularPhysicsList::ConstructProcess();
}

void PhysicsList::SetCuts() {
  SetCutsWithDefault();
}
