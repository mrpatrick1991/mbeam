i=19
for file in /home/patrick/phd/build/msis_xray_build/macros/sweep/*
do
  j=$((i*50 + 50))
  /home/patrick/phd/build/msis_xray_build/msis_xray "$file"
  mv /home/patrick/phd/build/msis_xray_build/ramdisk/output_h1_photon_KE_histogram_atm_slc_1035.csv /home/patrick/phd/build/msis_xray_build/ramdisk/output_h1_photon_KE_histogram_atm_slc_1035_run_keV_$j.csv
  mv /home/patrick/phd/build/msis_xray_build/ramdisk/output_h1_photon_theta_histogram_atm_slc_35.csv /home/patrick/phd/build/msis_xray_build/ramdisk/output_h1_photon_theta_histogram_atm_slc_35_run_keV_$j.csv
  mv /home/patrick/phd/build/msis_xray_build/ramdisk/output_h1_photon_phi_histogram_atm_slc_535.csv /home/patrick/phd/build/msis_xray_build/ramdisk/output_h1_photon_phi_histogram_atm_slc_535_run_keV_$j.csv

i=$((i+1))
done

