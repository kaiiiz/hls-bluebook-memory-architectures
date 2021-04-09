############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project LabA_window_2d
set_top avg
add_files hls-bluebook-memory-architectures/7.4-Caching/window_2d/src/singleport.cpp
add_files hls-bluebook-memory-architectures/7.4-Caching/window_2d/src/singleport_ram.hpp
add_files hls-bluebook-memory-architectures/7.4-Caching/window_2d/src/window_2d.cpp
add_files hls-bluebook-memory-architectures/7.4-Caching/window_2d/src/window_2d.h
add_files hls-bluebook-memory-architectures/7.4-Caching/window_2d/src/window_2d_problem.cpp
add_files -tb hls-bluebook-memory-architectures/7.4-Caching/window_2d/tb/test_window_2d.cpp
open_solution "problem"
set_part {xc7z020-clg484-1}
create_clock -period 5 -name default
#source "./LabA_window_2d/problem/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
