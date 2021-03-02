pro plot_xray_images

!PATH = Expand_Path('+E:\phd\idl\coyote') + ';' + !PATH
loadct, 13

fphi = read_csv("E:\phd\build\msis_xray_build\output_h1_photon_phi_histogram_atm_slc_534.csv", n_table_header=9)
fth = read_csv("E:\phd\build\msis_xray_build\output_h1_photon_theta_histogram_atm_slc_34.csv", n_table_header=9)

p = fphi.field1
t = fth.field1

p_samples = []
for i = 0, n_elements(p) - 1 do begin
  if (p[i] eq 0) then continue
  p_samples = [p_samples, make_array(p[i], /double, value = i)]
endfor

t_samples = []
for i = 0, n_elements(t) - 1 do begin
  if (t[i] eq 0) then continue
  t_samples = [t_samples, make_array(t[i], /double, value = i)]
endfor

r = 1.0
;x = r*sin(t_samples*!pi/180)*cos(p_samples*!pi/180)
;y = r*sin(t_samples*!pi/180)*sin(p_samples*!pi/180)

r =  cos(t_samples[where(t_samples gt 90)]*!pi/180) ; no backscatter, r in the x-y plane

x = r*cos(p_samples*!pi/180)
y =  r*sin(p_samples*!pi/180)




stop

xrange = [Min(x), Max(x)]

yrange = [Min(y), Max(y)]
xbinsize = 1.00
ybinsize = 1.00

; Open a display window.
cgDisplay

; Create the density plot by binning the data into a 2D histogram.
density = Hist_2D(x, y, Min1=xrange[0], Max1=xrange[1], Bin1=xbinsize, $
  Min2=yrange[0], Max2=yrange[1], Bin2=ybinsize)

maxDensity = Ceil(Max(density)/1e2) * 1e2
scaledDensity = BytScl(density, Min=0, Max=maxDensity)

; Load the color table for the display. All zero values will be gray.
cgLoadCT, 33
TVLCT, cgColor('gray', /Triple), 0
TVLCT, r, g, b, /Get
palette = [ [r], [g], [b] ]

; Display the density plot.
cgImage, scaledDensity, XRange=xrange, YRange=yrange, /Axes, Palette=palette, $
  XTitle='Concentration of X', YTitle='Concentration of Y', $
  Position=[0.125, 0.125, 0.9, 0.8]

end