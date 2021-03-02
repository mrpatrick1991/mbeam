pro plot_event_histograms
  loadct, 13

  km_0_100 = indgen(100)

  restore,  strcompress("E:\phd\build\msis_xray_build\data\edep_height_km_"+string(0)+".sav",/REMOVE_ALL)
  cgplot, edep_height_km, km_0_100, /xlog, color=cgcolor(1), xrange=[0.01,1000]

for j = 1, 10 do begin
  restore,  strcompress("E:\phd\build\msis_xray_build\data\edep_height_km_"+string(j)+".sav",/REMOVE_ALL)
  cgplot, edep_height_km, km_0_100, /xlog, color=cgcolor(j*10), /overplot
 
endfor

stop
end