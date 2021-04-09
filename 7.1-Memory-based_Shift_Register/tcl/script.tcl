############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project hls_labA_7-1
set_top shift_reg
add_files hls_labA/7.1-Memory-based_Shift_Register/src/circular_shift.h
add_files hls_labA/7.1-Memory-based_Shift_Register/src/shift_reg.cpp
add_files hls_labA/7.1-Memory-based_Shift_Register/src/shift_reg.h
add_files -tb hls_labA/7.1-Memory-based_Shift_Register/tb/tb_shift_reg.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xc7z020-clg400-1}
create_clock -period 5 -name default
#source "./hls_labA_7-1/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all -tool xsim
export_design -format ip_catalog
