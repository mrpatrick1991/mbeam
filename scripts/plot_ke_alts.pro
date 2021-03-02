pro plot_ke_alts

  !PATH = Expand_Path('+E:\phd\idl\coyote') + ';' + !PATH

  files = file_search("E:\phd\build\msis_xray_build\ramdisk\output*.csv")

  angles = indgen(180)

  cgLOADCT, 13, NCOLORS=255

  set_plot, 'ps'
  device, filename='E:\test.ps', /color, /inches, /landscape

  f = read_csv("E:\phd\build\msis_xray_build\ramdisk\output_h1_photon_KE_histogram_atm_slc_520.csv", n_table_header=9)
  cgplot, angles, 1.0*f.field1/max(f.field1), xrange=[0,180], label = "GEANT4 Photon Energy Distribution Through MSIS Model Atmosphere", xmargin=10,xtitle="Energy (keV)", ytitle="Normalized Count", background='black',AXISCOLOR ='white',SYMCOLOR='white'


  colorspace = indgen(21)*(255/21)

  for i =0,20 do begin
    j = i+21
    print, j
    fname = strcompress("E:\phd\build\msis_xray_build\ramdisk\output_h1_photon_KE_histogram_atm_slc_" + string(j+500) + ".csv",/REMOVE_ALL)
    fn = read_csv(fname, n_table_header=9)
    cgplot, angles, 1.0*fn.field1/max(fn.field1),/overplot,color=colorspace[i]
  endfor


  cgColorbar, Divisions=4, Minor=5, Format='(F0.2)', Ticklen=-0.25, /bottom, title="Alt (km)", /fit, range=[20,40], /vertical, tlocation="RIGHT",color="white"
  device,/close

end


;f = read_csv("E:\phd\build\msis_xray_build\ramdisk\output_h1_photon_theta_histogram_atm_slc_30.csv", n_table_header=9)
