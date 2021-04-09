############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project hls_labA_7-2
set_top interleave
add_files hls_labA/7.2-Memory_Organization/src/write_mem_seq.hpp
add_files hls_labA/7.2-Memory_Organization/src/write_mem_rnd.hpp
add_files hls_labA/7.2-Memory_Organization/src/read_mem_seq.hpp
add_files hls_labA/7.2-Memory_Organization/src/read_mem_rnd.hpp
add_files hls_labA/7.2-Memory_Organization/src/interleave_mem_seq.hpp
add_files hls_labA/7.2-Memory_Organization/src/interleave_mem_rnd.hpp
add_files hls_labA/7.2-Memory_Organization/src/interleave_manual_seq.cpp
add_files hls_labA/7.2-Memory_Organization/src/interleave_manual_rnd.cpp
add_files hls_labA/7.2-Memory_Organization/src/interleave.h
add_files hls_labA/7.2-Memory_Organization/src/interleave.cpp
add_files -tb hls_labA/7.2-Memory_Organization/tb/tb_interleave.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xc7k70t-fbv676-1}
create_clock -period 5 -name default
#source "./hls_labA_7-2/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all -tool xsim
export_design -format ip_catalog
