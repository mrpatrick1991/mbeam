#include "DetectorConstruction.hh"
#include "ActionInitialization.hh"
#include "G4MTRunManager.hh"
#include "G4UImanager.hh"
#include "PhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4StepLimiterPhysics.hh"
#include "G4ScoringManager.hh"
#include "Randomize.hh"
#include "G4UIExecutive.hh"

int main(int argc, char** argv) {
  // Detect interactive mode (if no arguments) and define UI session

  G4UIExecutive* ui = 0;
  if ( argc == 1 ) {
    ui = new G4UIExecutive(argc, argv);
  }

  // Choose the Random engine
  G4Random::setTheEngine(new CLHEP::RanecuEngine);

  // Construct the default run manager
  G4ScoringManager::GetScoringManager();
  G4MTRunManager* runManager = new G4MTRunManager;

  // Set mandatory initialization classes
  PhysicsList* physics_list = new PhysicsList();
  physics_list->RegisterPhysics(new G4EmStandardPhysics);

  runManager->SetUserInitialization(new DetectorConstruction());
  runManager->SetUserInitialization(physics_list);

  // Set user action classes
  runManager->SetUserInitialization(new ActionInitialization());

  // Get the pointer to the User Interface manager
  G4UImanager* UImanager = G4UImanager::GetUIpointer();

  // Process macro or start UI session and set macro directory
  UImanager->ApplyCommand("/control/macroPath macros");

  // Process macro or start UI session

  if ( ! ui ) {
    // batch mode
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command+fileName);
  }
  
  else {
    // interactive mode
    ui->SessionStart();
    delete ui;
  }

  ui->SessionStart();

  // Job termination
  // Free the store: user actions, physics_list and
  // detector_description are owned and deleted by the run manager, so
  // they should not be deleted in the main() program !

  delete runManager;
}
