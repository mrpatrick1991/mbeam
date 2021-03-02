pro plot_theta_at_alt

!PATH = Expand_Path('+E:\phd\idl\coyote') + ';' + !PATH
loadct, 13

file = "E:\phd\build\msis_xray_build\ramdisk\output_h1_photon_theta_histogram_atm_slc_32.csv"
file2 = "E:\phd\build\msis_xray_build\ramdisk\output_h1_photon_KE_histogram_atm_slc_532.csv"

f = read_csv(file2, n_table_header=8)
plot, f.field1

stop
end