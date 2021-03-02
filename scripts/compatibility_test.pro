pro compatibility_test

loadct, 13

files = file_search("E:\phd\data\GEANT4_runs\24-09-2018-011631-run__energy__particles__beamtype__source_alt_km_\*.csv")
print, "Found " + string(n_elements(files)) + " event data files."
event_count = 0


events = read_csv(strcompress(files[1],/REMOVE_ALL), count = event_count)


;for i = 0,1  do begin
;  print, "loading event file " + string(i) + " of " + string(n_elements(files))
;  events = [events, read_csv(strcompress(files[i],/REMOVE_ALL), count = event_count)]
;  print, "done"
;endfor

heights_km = make_array(event_count,/integer)
edep = make_array(event_count,/double)
n = make_array(event_count, /long)
px = make_array(event_count, /double)
py = make_array(event_count, /double)
pz = make_array(event_count, /double)
ke = make_array(event_count, /double)

km_0_500 = indgen(500)
theta_histograms = make_array(500,180,/long)
edep_height_km = make_array(500,/long)
nsecondaries_height_km = make_array(500,/long)

heights_km = events.field1
edep = events.field2
px = events.field3
py = events.field4
pz = events.field5
ke = events.field6

theta = 180/!PI*acos(pz)

for i =  0, km_0_500[-1] do begin
  edep_height_km[i] = total(edep[where(heights_km EQ i)])
  nsecondaries_height_km[i] = total(n[where(heights_km EQ i)])
  index = where(heights_km le i+1 and heights_km ge i)
endfor
;  if ((size(index))[2] gt 1) then begin
;    thetas = theta[index]
;    theta_histograms[i,*] = histogram(thetas, binsize = 1, max=180, min=1)
;  end
;endfor




;scored = read_csv(strcompress("E:\phd\build\msis_xray_build\data\eDep.csv",/REMOVE_ALL), count = event_count)


stop
end