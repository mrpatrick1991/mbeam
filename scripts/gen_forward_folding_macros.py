# Generate a directory of macros for msis_xray, one for each energy in
# keV of a sweep we want to do.

startKeV = 950
stopKeV = 1500
dE = 50

for i in range(startKeV,stopKeV,dE):
    f = open('/home/patrick/phd/build/msis_xray_build/macros/sweep/run_'+str(i)+'keV.mac','w+')
    f.write("""
/run/numberOfThreads 14
/control/macroPath macros
/run/initialize

/gps/particle e-
/gps/pos/type Point
/gps/pos/centre 0. 0. 500. km
/gps/ang/type cos
/gps/energy """+ str(i) + """ keV # Sweep

/analysis/h1/setActivationToAll false
/analysis/h1/setActivation 36 true
/analysis/h1/setActivation 536 true
/analysis/h1/setActivation 1036 true

/run/beamOn 1000000000""")
    f.close()
