#include "RunAction.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "DetectorConstruction.hh"

RunAction::RunAction()
    : G4UserRunAction()
{

  const DetectorConstruction *detector =
      (const DetectorConstruction *)(G4RunManager::GetRunManager()->GetUserDetectorConstruction());

  G4RunManager::GetRunManager()->SetPrintProgress(100);
  G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
  analysisManager->SetVerboseLevel(1);
  analysisManager->SetFirstHistoId(1);
  analysisManager->SetActivation(true);

  for (int i = 0; i < 500; i++)
  {
    analysisManager->CreateH1("photon_theta_histogram_atm_slc_" + std::to_string(i),
                              "photon polar angle histogram", 180, 0., 180 * degree);

    // all histograms start turned on unless they are deactivated in the macro
    // file.
  }

  for (int i = 500; i < 1000; i++)
  {
    analysisManager->CreateH1("photon_phi_histogram_atm_slc_" + std::to_string(i),
                              "photon az angle histogram", 360, 0., 360 * degree);

  }

  for (int j = 1000; j < 1500; j++)
  {
    analysisManager->CreateH1("photon_KE_histogram_atm_slc_" + std::to_string(j),
                              "photon kinetic energy histogram", 1000, 0., 1000 * keV);
  }

  /*for (int j = 1500; j  < 2000; j++) {
    analysisManager->CreateH1("electron_KE_histogram_atm_slc_" + std::to_string(j),
      "electron kinetic energy histogram", 1000, 0., 1000*keV);
  }

  for (int j = 2000; j  < 2500; j++) {
    analysisManager->CreateH1("electron_theta_histogram_atm_slc_" + std::to_string(j),
      "electron kinetic energy histogram", 180, 0., 180*degree);
  }

  for (int j = 2500; j  < 3000; j++) {
    analysisManager->CreateH1("photon_px_histogram_atm_slc_" + std::to_string(j),
      "photon x momentum histogram", 1000, -1000*keV, 1000*keV);
  }

  for (int j = 3000; j  < 3500; j++) {
    analysisManager->CreateH1("photon_py_histogram_atm_slc_" + std::to_string(j),
      "photon y momentum histogram", 1000, -1000*keV, 1000*keV);
  }

  for (int j = 3500; j  < 4000; j++) {
    analysisManager->CreateH1("photon_pz_histogram_atm_slc_" + std::to_string(j),
      "photon z momentum histogram", 1000, -1000*keV, 1000*keV);
  }


  /*for (int j = 1500; j  < 2000; j++) {
    analysisManager->CreateH2("photon_2d_momentum_histogram_atm_slc_" + std::to_string(j),
      "photon xy momentum histogram", 64, -1, 1, 64, -1, 1);
  }*/

  analysisManager->OpenFile("ramdisk/output");
}

RunAction::~RunAction()
{
}

void RunAction::BeginOfRunAction(const G4Run *)
{
  //inform the runManager to save random number seed
  G4RunManager::GetRunManager()->SetRandomNumberStore(false);
  G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
}

void RunAction::EndOfRunAction(const G4Run *run)
{

  //save histograms
  G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
  analysisManager->Write();
  analysisManager->CloseFile();

  analysisManager->OpenFile("ramdisk/events_run_" + std::to_string(run->GetRunID()));
}
