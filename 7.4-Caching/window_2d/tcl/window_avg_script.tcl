############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project LabA_window_2d
set_top window_avg
add_files hls-bluebook-memory-architectures/7.4-Caching/window_2d/src/window_2d_problem.cpp
add_files hls-bluebook-memory-architectures/7.4-Caching/window_2d/src/window_2d.h
add_files hls-bluebook-memory-architectures/7.4-Caching/window_2d/src/window_2d.cpp
add_files hls-bluebook-memory-architectures/7.4-Caching/window_2d/src/singleport_ram.hpp
add_files hls-bluebook-memory-architectures/7.4-Caching/window_2d/src/singleport.cpp
add_files -tb hls-bluebook-memory-architectures/7.4-Caching/window_2d/tb/test_window_2d.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb hls-bluebook-memory-architectures/7.4-Caching/window_2d/tb/test_singleport_ram.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "window"
set_part {xc7z020-clg484-1}
create_clock -period 5 -name default
config_sdx -target none
config_export -vivado_optimization_level 2 -vivado_phys_opt place -vivado_report_level 0
set_clock_uncertainty 12.5%
#source "./LabA_window_2d/window/directives.tcl"
csim_design
csynth_design
cosim_design -tool xsim
export_design -format ip_catalog
