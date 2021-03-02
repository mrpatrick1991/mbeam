#define CSV_IO_NO_THREAD // required for the third party csv library to
                         // work with GEANT4 multi-threading.

#include <G4VisAttributes.hh>
#include <stdio.h>
#include "csv.h"
#include "DetectorConstruction.hh"
#include "G4GeometryManager.hh"
#include "G4Material.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Cons.hh"
#include "G4Sphere.hh"
#include "G4FieldManager.hh"
#include "G4TransportationManager.hh"
#include "TrackerSD.hh"
#include "G4SDManager.hh"
#include "G4NistManager.hh"
#include "G4Element.hh"
#include "globals.hh"

// MSIS model file name

G4String MSIS_MODEL_FILE = "msis_query.csv";

// define simulation dimension constants

//const G4double WORLD_SIZE_XY = 1000000*km; // chosen to be essentially


                                          // infinity.
const G4double WORLD_SIZE_XY = 1000000*km;
int csv_row_total = 0;
// physics constants

const G4double AVOGADRO = 6.0221409e+23;

G4VisAttributes* leadVisAttributes = new G4VisAttributes(G4Colour(.6,.0,.9));

DetectorConstruction::DetectorConstruction()
:G4VUserDetectorConstruction()
{}

DetectorConstruction::~DetectorConstruction()
{}

G4VPhysicalVolume* DetectorConstruction::Construct() {

  G4GeometryManager::GetInstance()->SetWorldMaximumExtent(2.*WORLD_SIZE_XY);
  G4bool checkOverlaps = true;

  G4NistManager* matMan = G4NistManager::Instance();

  // Create the world volume into which all else gets placed

  // Define a vacuum material to use for initialization purposes and to
  // fill empty space

  G4Material* vacuum = new G4Material("Galactic", 1., 1.01*g / mole,
                                    1.e-25, kStateGas, 0.1*kelvin,
                                    1.e-19*pascal);

                                    // get the number of lines in the MSIS input file

                                    double heightkm, O, N2, O2, rho, He, Ar, H, N;
                                    io::CSVReader<9> in(MSIS_MODEL_FILE);
                                    double max_msis_height_km = 0.0;
                                    while (in.read_row(heightkm, O, N2, O2, rho, He, Ar, H, N)) {
                                  	  csv_row_total++;
                                  	  max_msis_height_km = heightkm*km;
                                    }

                                    double msis_layer_height_km = max_msis_height_km / (csv_row_total - 1);

                                    std::cout << "Opened MSIS atmosphere data file. Found: " +
                                      std::to_string(csv_row_total) + " sample points.\n";

                                    std::cout << "Atmosphere max height is: " +
                                      std::to_string(max_msis_height_km) + " \n";

                                    std::cout << "Atmosphere slab height is: " +
                                      std::to_string(msis_layer_height_km) + " \n";



  G4Material* world_mat = vacuum;
  // must be slightly bigger than env
  G4Box* solidWorld = new G4Box("World",
	  WORLD_SIZE_XY*(1.01) / 2.0,
	  WORLD_SIZE_XY*(1.01) / 2.0,
	  max_msis_height_km*(1.01) / 2.0);

  G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld,
	  world_mat, "World");

  G4VPhysicalVolume* physWorld = new G4PVPlacement(0,
	  G4ThreeVector(0, 0, 0),
	  logicWorld,
	  "World",
	  0,
	  false,
	  0,
	  checkOverlaps);

  // Create the elements used to make the model atmosphere

  G4double aO = 15.999;
  G4Element* elO = new G4Element("Oxygen", "O", 8., aO*g / mole);

  G4double aN = 14.0067;
  G4Element* elN = new G4Element("Nitrogen", "N", 7., aN*g / mole);

  G4double aHe = 4.002602;
  G4Element* elHe = new G4Element("Helium", "He", 2., aHe*g / mole);

  G4double aAr = 39.948;
  G4Element* elAr = new G4Element("Argon", "Ar", 18., aAr*g / mole);

  G4double aH = 1.00794;
  G4Element* elH = new G4Element("Hydrogen", "H", 1., aH*g / mole);

  // these are computed to make the atmosphere material for each
  // sample point

  double elOMassFraction, elN2MassFraction, elO2MassFraction;
  double elHeMassFraction, elArMassFraction, elNMassFraction;
  double elHMassFraction;

  io::CSVReader<9> in2(MSIS_MODEL_FILE);
  int index = 0;
  double surface_rho = 0.0;
  while (in2.read_row(heightkm, O, N2, O2, rho, He, Ar, H, N)) {

    if (index == 0){
      surface_rho = rho;
    }

    G4Material *atm_mat = new G4Material("atm_slc_" + std::to_string(index),
		rho*g / cm3, 7);

	elOMassFraction = O * aO / (rho*AVOGADRO);
	elN2MassFraction = N2 * aN * 2 / (rho*AVOGADRO);
	elO2MassFraction = O2 * aO * 2 / (rho*AVOGADRO);
	elHeMassFraction = He * aHe / (rho*AVOGADRO);
	elHMassFraction = H * aH / (rho*AVOGADRO);
	elArMassFraction = Ar * aAr / (rho*AVOGADRO);
	elNMassFraction = N * aN / (rho*AVOGADRO);

	atm_mat->AddElement(elO, elOMassFraction);
	atm_mat->AddElement(elN, elN2MassFraction);
	atm_mat->AddElement(elO, elO2MassFraction);
	atm_mat->AddElement(elHe, elHeMassFraction);
	atm_mat->AddElement(elAr, elArMassFraction);
	atm_mat->AddElement(elN, elNMassFraction);
	atm_mat->AddElement(elH, elHMassFraction);

	// dimensions are specifed as half-lengths
	G4Box *atm_shape = new G4Box("atm_slc_",
		WORLD_SIZE_XY / 2.0, WORLD_SIZE_XY / 2.0,
		msis_layer_height_km / 2.0);

	G4ThreeVector atm_pos = G4ThreeVector(0, 0, (-max_msis_height_km) / 2.0 +
		  (index*msis_layer_height_km));

	G4LogicalVolume *atm_logv = new G4LogicalVolume(atm_shape,
		  atm_mat,
		  "atm_slc_lv");

  atm_logv->SetVisAttributes(leadVisAttributes);

  double a = double(rho) / double(surface_rho);

	new G4PVPlacement(0,
		atm_pos,
		atm_logv,
		"atm_slc_pv", logicWorld, false, index, checkOverlaps);
	  index++;
  }

  return physWorld;
}

int DetectorConstruction::getMSISLayerCount() {
  return csv_row_total;
}

void DetectorConstruction::ConstructSDandField() {
	G4String SDname = "atm_SD";

	TrackerSD* atmTracker = new TrackerSD(SDname, "TrackerHitsCollection");
	G4SDManager::GetSDMpointer()->AddNewDetector(atmTracker);
	SetSensitiveDetector("atm_slc_lv", atmTracker, true);

}
