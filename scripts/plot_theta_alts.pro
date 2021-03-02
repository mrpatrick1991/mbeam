pro plot_theta_alts

  !PATH = Expand_Path('+E:\phd\idl\coyote') + ';' + !PATH
  
  files = file_search("E:\phd\build\msis_xray_build\ramdisk\output*.csv")

cgLOADCT, 13, NCOLORS=255

f = read_csv("E:\phd\build\msis_xray_build\ramdisk\output_h1_photon_theta_histogram_atm_slc_20.csv", n_table_header=9)
cgplot, angles, 1.0*f.field1/max(f.field1), xrange=[0,180], label = "GEANT4 Photon Energy Polar Angle Distribution Through MSIS Model Atmosphere", xtitle="Polar Angle (deg)", ytitle="Normalized Count", background='black', yrange=[0,1.05]


colorspace = indgen(21)*(255/21)

for i =0,20 do begin
  j = i+21
  print, j
  fname = strcompress("E:\phd\build\msis_xray_build\ramdisk\output_h1_photon_theta_histogram_atm_slc_" + string(j) + ".csv",/REMOVE_ALL)
  fn = read_csv(fname, n_table_header=9)
  cgplot, angles, 1.0*fn.field1/max(fn.field1),/overplot,color=colorspace[i]
endfor


cgColorbar, Divisions=4, Minor=5, Format='(F0.2)', Ticklen=-0.25, /bottom, title="Alt (km)", /fit, range=[20,40], /vertical, tlocation="RIGHT"



;f30 = read_csv("E:\phd\build\msis_xray_build\ramdisk\output_h1_photon_theta_histogram_atm_slc_30.csv", n_table_header = 9)
;f31 = read_csv("E:\phd\build\msis_xray_build\ramdisk\output_h1_photon_theta_histogram_atm_slc_31.csv", n_table_header = 9)
;f;32 = read_csv("E:\phd\build\msis_xray_build\ramdisk\output_h1_photon_theta_histogram_atm_slc_32.csv", n_table_header = 9)
;f33 = read_csv("E:\phd\build\msis_xray_build\ramdisk\output_h1_photon_theta_histogram_atm_slc_33.csv", n_table_header = 9)
;f34 = read_csv("E:\phd\build\msis_xray_build\ramdisk\output_h1_photon_theta_histogram_atm_slc_34.csv", n_table_header = 9)
;f35 = read_csv("E:\phd\build\msis_xray_build\ramdisk\output_h1_photon_theta_histogram_atm_slc_35.csv", n_table_header = 9)




;f50 = read_csv("E:\phd\build\msis_xray_build\ramdisk\output_h1_photon_theta_histogram_atm_slc_50.csv", n_table_header = 9)
;f60 = read_csv("E:\phd\build\msis_xray_build\ramdisk\output_h1_photon_theta_histogram_atm_slc_60.csv", n_table_header = 9)
 
;cgplot, angles, f30.field1*1.0/max(f30.field1), /overplot, color=20
;cgplot, angles, f31.field1*1.0/max(f31.field1), /overplot, color=40
;cgplot, angles, f32.field1*1.0/max(f32.field1), /overplot,color=60
;cgplot, angles, f33.field1*1.0/max(f33.field1), /overplot,color=80
;cgplot, angles, f34.field1*1.0/max(f34.field1), /overplot,color=100
;cgplot, angles, f35.field1*1.0/max(f35.field1), /overplot,color=120





  stop
end

;f = read_csv("E:\phd\build\msis_xray_build\ramdisk\output_h1_photon_theta_histogram_atm_slc_30.csv", n_table_header=9)
