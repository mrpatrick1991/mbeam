init_crib_colors

a = make_array(600)

for i=1,600 do begin
  a[i] =(((read_ascii(strcompress('/home/patrick/phd/svn/GEANT4/msis_xray_build/_h1_'+string(i)+'.csv',/remove_all), delimiter=',',data_start=9)).field1)[0,*])[*]
endfor

end
