i=0
for file in /home/patrick/phd/build/msis_xray_build/macros/sweep/*
do
  /home/patrick/phd/build/msis_xray_build/msis_xray "$file"
  mv /home/patrick/phd/build/msis_xray_build/ramdisk/output_h1_photon_KE_histogram_atm_slc_1035.csv /home/patrick/phd/data/GEANT4_runs/15-05-2019_photon_distributions_35km_cosine_beams_monoenergetic_sweep$i.csv
i=$((i+1))
done

