pro plot_xray_images_rev_2

  set_plot, 'ps'
  device, filename='E:\test.ps', /color, /inches, /landscape

!PATH = Expand_Path('+E:\phd\idl\coyote') + ';' + !PATH
loadct, 13

f = read_csv("E:\phd\build\msis_xray_build\output_h2_photon_2d_momentum_histogram_atm_slc_1550.csv", n_table_header=10)

image_xy = 64

; every row of 64 begins with two overflow/underflow bins. Remove them to make the 64x64 image

image = (reform(f.field1,66,66))[2:-1,2:-1]

cgLoadCT, 33
TVLCT, cgColor('black', /Triple), 0
TVLCT, r, g, b, /Get
palette = [ [r], [g], [b] ]

image_rebin_xy = 16

image = rebin(image,image_rebin_xy,image_rebin_xy)

data = image

sf = 256/max(image)

; Display the density plot.
cgImage, image*sf, XRange=xrange, YRange=yrange, /Axes, Palette=palette, $
  XTitle='X (px)', YTitle='Y (px)',/KEEP_ASPECT_RATIO, title="GEANT4 X-ray Image, Beam Source, 50 Km Detector Altitude"

  ; Set up for drawing 25% and 75% circles.
  points = (2 * !PI / 99.0) * FINDGEN(100)
  xcenter = image_rebin_xy/2
  ycenter = image_rebin_xy/2
  


  thick = (!D.Name EQ 'PS') ? 4 : 2

  ; Draw 25% circle.
  for i=1,6,2 do begin
    r = image_rebin_xy/2*sin((!PI/180)*(i+1)*10) 
    x = xcenter + r * Cos(points)
    y = ycenter + r * Sin(points)
    cgPlotS, x, y, Color='white', Thick=thick
    cgText, xcenter + r*cos(45*!PI/180), ycenter + r*sin(45*!PI/180), /Data, Color='white', string(i*10)+'$\deg$', Alignment=0.5

  endfor

  cgColorbar, Divisions=max(image), Minor=0, Format='(F0.2)', Ticklen=-0.25, /vertical, /fit, title="Photon Count", range=[0,max(image)],$
/right
device,/close

stop
end

