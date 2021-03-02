pro imaging

  !PATH = Expand_Path('+E:\phd\idl\coyote') + ';' + !PATH

  OpenR, lun, 'E:\phd\build\msis_xray_build\1MeV_fSC_beam1d_500km_source_alt_run.csv', /Get_Lun
  Point_Lun, lun, 0
  ReadF, lun, adim, bdim, cdim, ddim, num_columns

array = intarr(6, 10000) 

readF, lun, array

free_lun, lun

stop
end 