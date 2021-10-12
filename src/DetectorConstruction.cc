#include <G4VisAttributes.hh>
#include <iomanip>
#include "DetectorConstruction.hh"
#include "G4GeometryManager.hh"
#include "G4Material.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4Box.hh"
#include "G4TransportationManager.hh"
#include "TrackerSD.hh"
#include "G4SDManager.hh"
#include "G4NistManager.hh"
#include "G4Element.hh"
#include "nrlmsise-00.hh"
#include "Config.hh"

G4bool checkOverlaps = true;

const G4double AVOGADRO = 6.0221409e+23;

const G4double WORLD_SIZE_XY = 1000000 * km; // infinity

G4double aO = 15.999;
G4Element *elO = new G4Element("Oxygen", "O", 8., aO *g / mole);

G4double aN = 14.0067;
G4Element *elN = new G4Element("Nitrogen", "N", 7., aN *g / mole);

G4double aHe = 4.002602;
G4Element *elHe = new G4Element("Helium", "He", 2., aHe *g / mole);

G4double aAr = 39.948;
G4Element *elAr = new G4Element("Argon", "Ar", 18., aAr *g / mole);

G4double aH = 1.00794;
G4Element *elH = new G4Element("Hydrogen", "H", 1., aH *g / mole);

double elOMassFraction, elN2MassFraction, elO2MassFraction;
double elHeMassFraction, elArMassFraction, elNMassFraction;
double elHMassFraction;

struct nrlmsise_output msis_output;
struct nrlmsise_input msis_input;
struct nrlmsise_flags msis_flags;
struct ap_array aph;

DetectorConstruction::DetectorConstruction()
    : G4VUserDetectorConstruction()
{
}

DetectorConstruction::~DetectorConstruction()
{
}

G4VPhysicalVolume *DetectorConstruction::Construct()
{
  G4GeometryManager::GetInstance()->SetWorldMaximumExtent(WORLD_SIZE_XY);

  G4Material *vacuum = new G4Material("Galactic", 1., 1.01 * g / mole,
                                      1.e-25, kStateGas, 0.1 * kelvin, 1.e-19 * pascal);

  G4Box *solidWorld = new G4Box("World",
                                WORLD_SIZE_XY * (1.01), WORLD_SIZE_XY * (1.01), WORLD_SIZE_Z * 2 * (1.01));

  G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, vacuum, "World");

  G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0, 0, 0), logicWorld, "World",
                                                   0, false, 0, true);

  for (int i = 0; i < MSIS_N_SLICE; i++)
  {
    G4cout << "Building atmosphere slice " + std::to_string(i) + "...\n";
    G4cout << "Altitude for this slice is: " + std::to_string(i * (WORLD_SIZE_Z / MSIS_N_SLICE) / 2000000.0) + " km.\n";
    msis_input.doy = MSIS_DOY;
    msis_input.year = 0;
    msis_input.sec = 0;
    msis_input.g_lat = MSIS_LAT_DEG;
    msis_input.g_long = MSIS_LON_DEG;
    msis_input.lst = MSIS_LST;
    msis_input.f107A = MSIS_F107A;
    msis_input.f107 = MSIS_F107;
    msis_input.ap = MSIS_AP;

    G4double msis_layer_height_km = WORLD_SIZE_Z / (MSIS_N_SLICE);

    msis_flags.switches[0] = 0; // this is the recommended configuration for msis.
    for (int j = 1; j < 24; j++)
    {
      msis_flags.switches[j] = 1;
    }
    msis_flags.switches[0] = 0; // use g/cm^3 units for densities

    msis_input.alt = i * (WORLD_SIZE_Z / MSIS_N_SLICE) / 2000000.0;

    gtd7(&msis_input, &msis_flags, &msis_output);

    G4cout << "nHe: " << std::scientific << std::setprecision(16) << msis_output.d[0] << "\n";
    G4cout << "nO: " << std::scientific << std::setprecision(16) << msis_output.d[1] << "\n";
    G4cout << "nN2: " << std::scientific << std::setprecision(16) << msis_output.d[2] << "\n";
    G4cout << "nO2: " << std::scientific << std::setprecision(16) << msis_output.d[3] << "\n";
    G4cout << "nAr: " << std::scientific << std::setprecision(16) << msis_output.d[4] << "\n";
    G4cout << "nH: " << std::scientific << std::setprecision(16) << msis_output.d[6] << "\n";
    G4cout << "nN: " << std::scientific << std::setprecision(16) << msis_output.d[7] << "\n";
    G4cout << "Rho: " << std::scientific << std::setprecision(16) << msis_output.d[5] << "\n";
    G4cout << "\n";

    G4double rho = msis_output.d[5] * (g / cm3);

    G4Material *atm_mat = new G4Material("atm_slc_" + std::to_string(i), rho, 7);

    elOMassFraction = (g / cm3) * msis_output.d[1] * aO / (rho * AVOGADRO);
    elHeMassFraction = (g / cm3) * msis_output.d[0] * aHe / (rho * AVOGADRO);
    elHMassFraction = (g / cm3) * msis_output.d[6] * aH / (rho * AVOGADRO);
    elArMassFraction = (g / cm3) * msis_output.d[4] * aAr / (rho * AVOGADRO);
    elNMassFraction = (g / cm3) * msis_output.d[7] * aN / (rho * AVOGADRO);
    elN2MassFraction = (g / cm3) * msis_output.d[2] * aN * 2.0 / (rho * AVOGADRO);
    elO2MassFraction = (g / cm3) * msis_output.d[3] * aO * 2.0 / (rho * AVOGADRO);

    G4Material *N2 = new G4Material("N2_" + std::to_string(i), (G4double)(g / cm3) * msis_output.d[2] * aN / (AVOGADRO), 1);
    N2->AddElement(elN, 2);

    G4Material *O2 = new G4Material("O2_" + std::to_string(i), (G4double)(g / cm3) * msis_output.d[3] * aO / (AVOGADRO), 1);
    O2->AddElement(elO, 2);

    atm_mat->AddElement(elO, elOMassFraction);
    atm_mat->AddElement(elN, elNMassFraction);
    atm_mat->AddElement(elHe, elHeMassFraction);
    atm_mat->AddElement(elAr, elArMassFraction);
    atm_mat->AddElement(elH, elHMassFraction);
    atm_mat->AddMaterial(O2, elO2MassFraction);
    atm_mat->AddMaterial(N2, elN2MassFraction);

    // dimensions are specifed as half-lengths
    G4Box *atm_shape = new G4Box("atm_slc_",
                                 WORLD_SIZE_XY / 2.0, WORLD_SIZE_XY / 2.0, msis_layer_height_km / 2.0);

    G4ThreeVector atm_pos = G4ThreeVector(0, 0, -(WORLD_SIZE_Z) / 2.0 + (i * msis_layer_height_km));
    G4LogicalVolume *atm_logv = new G4LogicalVolume(atm_shape, atm_mat, "atm_slc_lv_" + std::to_string(i));
    G4PVPlacement *atm_pvpl = new G4PVPlacement(0, atm_pos, atm_logv, "atm_slc_pv", logicWorld, false, i, checkOverlaps);
  }

  G4cout << "Model atmosphere construction finished.\n";

  return physWorld;
}

void DetectorConstruction::ConstructSDandField()
{
  G4String SDname = "atm_SD";
  TrackerSD *atmTracker = new TrackerSD(SDname, "TrackerHitsCollection");
  G4SDManager::GetSDMpointer()->AddNewDetector(atmTracker);
  SetSensitiveDetector("atm_slc_lv_" + std::to_string(MSIS_SENSITIVE_SLICE), atmTracker, true);
}

