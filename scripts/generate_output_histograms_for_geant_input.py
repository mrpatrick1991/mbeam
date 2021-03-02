# The output histograms from this GEANT4 program can't be used as input in
# a macro file for another geant program. Read the csv theta, phi, and
# energy distributions and then convert them to new files:
# ene_in.mac, theta_in.mac, and phi_in.mac. Finally copy them all to
# the ABOVE2 src directory. Cmake on ABOVE2 then copies the new files over
# to be run as input on the ABOVE2 detector.

import csv
import numpy as np
import numpy.polynomial.polynomial as poly
import matplotlib.pyplot as plt
from math import *
import sys


inTheta = open('/home/patrick/phd/build/msis_xray_build/ramdisk/output_h1_photon_theta_histogram_atm_slc_35.csv', 'r')
inPhi = open('/home/patrick/phd/build/msis_xray_build/ramdisk/output_h1_photon_phi_histogram_atm_slc_535.csv', 'r')
inE = open('/home/patrick/phd/build/msis_xray_build/ramdisk/output_h1_photon_KE_histogram_atm_slc_1035.csv', 'r')

#inTheta = open(sys.argv[1], 'r')
#inPhi = open(sys.argv[2], 'r')
#inE = open(sys.argv[3], 'r')

outTheta = open('/home/patrick/phd/build/ABOVE2_build/macros/theta_in.mac','w+')
outPhi = open('/home/patrick/phd/build/ABOVE2_build/macros/phi_in.mac','w+')
outE = open('/home/patrick/phd/build/ABOVE2_build/macros/ene_in.mac','w+')

i=0
x = []
y = []
for line in inTheta:
    if line.startswith("#"):
        continue
    if line.startswith("e"):
        continue

    x.append(i)
    y.append(int(line.split(',')[1]))
    i = i + 1

nl = np.linspace(x[0],x[-1],25)
x = np.array(x)
y = np.array(y)
coefs = poly.polyfit(x, y, 20)
ffit = poly.polyval(nl, coefs)

i = 0
for point in nl:
    if (ffit[i] < 0):
        ffit[i] = 0


    outTheta.write('/gps/hist/point ' + str((nl[i]*3.14159/180.0)) +  ' ' + str(int(ffit[i])*cos(nl[i]*3.14159/180.0)) + '\n')
    i = i + 1

plt.plot(x,y)
plt.plot(nl, ffit)

plt.show()

i=0
x = []
y = []
for line in inPhi:
    if line.startswith("#"):
        continue
    if line.startswith("e"):
        continue

    x.append(i)
    y.append(int(line.split(',')[1]))
    i = i + 1

nl = np.linspace(x[0],x[-1],10)
x = np.array(x)
y = np.array(y)
coefs = poly.polyfit(x, y, 4)
ffit = poly.polyval(nl, coefs)

plt.plot(x,y)
plt.plot(nl, ffit)
plt.show()

i = 0
for point in nl:
    if (ffit[i] < 0):
        ffit[i] = 0
    outPhi.write('/gps/hist/point ' + str(i) +  '. ' + str(int(ffit[i])) + '\n')
    i = i + 1

i=0
x = []
y = []
for line in inE:
    if line.startswith("#"):
        continue
    if line.startswith("e"):
        continue

    x.append(i)
    y.append(int(line.split(',')[1]))
    i = i + 1

nl = np.linspace(x[0],x[200],50)
x = np.array(x)
y = np.array(y)
coefs = poly.polyfit(x[0:200], y[0:200], 4)
ffit = poly.polyval(nl, coefs)
plt.plot(x,y)
plt.plot(nl, ffit)
plt.show()


i = 0
for point in y :
    if (point < 0):
        point = 0
    outE.write('/gps/hist/point ' + str(float(i)/1000) +  ' ' + str(int(y[i])) + '\n')
    i = i + 1


outTheta.close()
outPhi.close()
outE.close()
