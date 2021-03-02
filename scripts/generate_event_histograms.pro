pro generate_event_histograms

for j = 0, 25 do begin

  events = read_csv(strcompress("E:\phd\build\msis_xray_build\data\events_run_" + string(j) +"_clean.csv",/REMOVE_ALL), count = event_count)
  heights_km = make_array(event_count,/integer)
  edep = make_array(event_count,/double)
  theta = make_array(event_count,/double)

  km_0_100 = indgen(100)
  edep_height_km = make_array(100,/double)

  heights_km = events.field1
  edep = events.field2
  theta = events.field3


  for i =  0, km_0_100[-1] do begin
    edep_height_km[i] = total(edep[where(heights_km EQ i)])
  endfor

  save, edep_height_km, filename = strcompress("E:\phd\build\msis_xray_build\data\edep_height_km_"+string(j)+".sav",/REMOVE_ALL)
  print, j
endfor

stop
end