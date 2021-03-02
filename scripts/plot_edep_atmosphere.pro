pro plot_edep_atmosphere

!PATH = Expand_Path('+E:\phd\idl\coyote') + ';' + !PATH
loadct, 13


files = file_search("E:\phd\data\GEANT4_runs\14-11-2018-eDep_30KeV_1e6_particles_500km_lambert_beam_pbc_10000km\*.csv")

energies_kev = indgen(10)*100

f = read_csv(strcompress(files[0],/REMOVE_ALL), n_table_header=3)
cgplot, f.field4*1000, f.field3, /xlog, xrange=[.01,1e8], label = "GEANT4 Photon Energy Deposition Through MSIS Model Atmosphere", xtitle="Energy Deposition (keV/s)", ytitle="alt (km)", background='black'

for i = 1,n_elements(files) -1 do begin
  f = read_csv(strcompress(files[i],/REMOVE_ALL), n_table_header=3)
  cgplot, f.field4*1000, f.field3, /overplot, color=i*256/(10)
endfor

;cgColorbar, Divisions=4, Minor=5, Format='(F0.2)', Ticklen=-0.25, /vertical, title="Electron Energy (KeV)", /fit
stop
end