############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project LabA_window_1d
set_top avg
add_files hls-bluebook-memory-architectures/7.4-Caching/window_1d/src/shift_class.hpp
add_files hls-bluebook-memory-architectures/7.4-Caching/window_1d/src/window_1d.h
add_files hls-bluebook-memory-architectures/7.4-Caching/window_1d/src/window_1d_poor_arch.cpp
add_files hls-bluebook-memory-architectures/7.4-Caching/window_1d/src/window_1d_sliding.cpp
add_files -tb hls-bluebook-memory-architectures/7.4-Caching/window_1d/tb/test_window_1d.cpp
open_solution "poor_arch"
set_part {xc7z020clg484-1}
create_clock -period 5 -name default
#source "./LabA_window_1d/poor_arch/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
