#ifndef Config_h
#define Config_h 1

#define MSIS_N_SLICE 500                 // number of atmosphere slabs to model, each with height WORLD_SIZE_Z/MSIS_N_SLICE.
const G4int  MSIS_SENSITIVE_SLICE = 30;  // slice of atmosphere to evaluate histograms at
const G4double WORLD_SIZE_Z = 1000 * km; // this means to sample MSIS from 0 to 500 km AGL.

#define MSIS_LAT_DEG 51.000; // coordinates to sample the MSIS atmosphere at
#define MSIS_LON_DEG 114.000;
#define MSIS_DOY 1;
#define MSIS_LST 16;
#define MSIS_F107 100;
#define MSIS_F107A 100;
#define MSIS_AP 4;

#endif
