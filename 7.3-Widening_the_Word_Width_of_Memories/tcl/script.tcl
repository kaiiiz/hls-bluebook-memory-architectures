############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project hls_labA_7-3
set_top word_width_manual
add_files hls_labA/7.3-Widening_the_Word_Width_of_Memories/src/word_width.cpp
add_files hls_labA/7.3-Widening_the_Word_Width_of_Memories/src/word_width.h
add_files hls_labA/7.3-Widening_the_Word_Width_of_Memories/src/word_width_manual.cpp
add_files hls_labA/7.3-Widening_the_Word_Width_of_Memories/src/word_width_mem.hpp
add_files hls_labA/7.3-Widening_the_Word_Width_of_Memories/src/ww_read_mem.hpp
add_files hls_labA/7.3-Widening_the_Word_Width_of_Memories/src/ww_write_mem.hpp
add_files -tb hls_labA/7.3-Widening_the_Word_Width_of_Memories/tb/tb_word_width.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xc7z020-clg400-1}
create_clock -period 5 -name default
#source "./hls_labA_7-3/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all -tool xsim
export_design -format ip_catalog
