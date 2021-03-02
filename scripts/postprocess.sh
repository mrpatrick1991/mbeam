dir=/mnt/hgfs/phd/data/GEANT4_runs/$(date '+%d-%m-%Y-%H%M%S')-run_$1_energy_$2_particles_$3_beamtype_$4_source_alt_km_$5
mkdir $dir

for file in /mnt/hgfs/phd/build/msis_xray_build/ramdisk/*;
do
 echo $file
 sed '/^#/ d' $file >> $file.clean
 mv $file.clean $dir
 rm $file
done

for file in $dir/*;
do
  mv $file "${file%.*}"
done
