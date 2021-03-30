#include "RunAction.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "DetectorConstruction.hh"
#include "Analysis.hh"
#include "Config.hh"

RunAction::RunAction()
    : G4UserRunAction()
{

  G4RunManager::GetRunManager()->SetPrintProgress(100);
  G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
  analysisManager->SetVerboseLevel(1);
  analysisManager->SetFirstHistoId(1);
  analysisManager->SetActivation(true);

  analysisManager->CreateH1("photon_theta_histogram_atm_slc_" + std::to_string(MSIS_SENSITIVE_SLICE),
                            "photon polar angle histogram", 180, 0., 180 * degree);
  analysisManager->CreateH1("photon_KE_histogram_atm_slc_" + std::to_string(MSIS_SENSITIVE_SLICE),
                            "photon kinetic energy histogram", 2000, 0., 1000 * keV);
  analysisManager->OpenFile("output");
}

RunAction::~RunAction()
{
}

void RunAction::BeginOfRunAction(const G4Run *)
{
  G4RunManager::GetRunManager()->SetRandomNumberStore(false);
}

void RunAction::EndOfRunAction(const G4Run *run)
{
  G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
  analysisManager->OpenFile("events_run_" + std::to_string(run->GetRunID()));
  analysisManager->Write();
  analysisManager->CloseFile();
}
