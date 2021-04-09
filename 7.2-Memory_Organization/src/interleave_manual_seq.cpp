#include "interleave.h"
#include "interleave_mem_seq.hpp"

void interleave_manual_seq(ap_int<8> x_in[NUM_WORDS],
                           ap_int<8> y[NUM_WORDS / 3], bool load) {
#pragma HLS RESOURCE variable=x_in core=RAM_1P_BRAM
#pragma HLS RESOURCE variable=y core=RAM_1P_BRAM

  static interleave_mem_seq<ap_int<8>, NUM_WORDS> x;
  int idx = 0;

  if (load)
LOAD:
    for (int i = 0; i < NUM_WORDS; i += 1)
#pragma HLS PIPELINE II=1
    	x.write_seq(i, x_in);
  else
WRITE:
    for (int i = 0; i < NUM_WORDS / 3; i += 1)
#pragma HLS PIPELINE II=1
    	// Some Modification Here
    	// Follow the description in book but not code
    	y[idx++] = x.read_seq(i, 0) + x.read_seq(i, 1) + x.read_seq(i, 2);
}
