#include "interleave.h"
#include "interleave_mem_rnd.hpp"

void interleave_manual_rnd(ap_int<8> x_in[NUM_WORDS],
                           ap_int<8> y[NUM_WORDS / 3], bool load) {
#pragma HLS RESOURCE variable=x_in core=RAM_1P_BRAM
#pragma HLS RESOURCE variable=y core=RAM_1P_BRAM

  static interleave_mem_rnd<ap_int<8>, NUM_WORDS> x;
  int idx = 0;

  if (load)
LOAD:
    for (int i = 0; i < NUM_WORDS; i += 1)
#pragma HLS PIPELINE II=1
    	x.write_rnd(i, x_in);
  else
WRITE:
    for (int i = 0; i < NUM_WORDS; i += 3)
#pragma HLS PIPELINE II=1
      y[idx++] = x.read_rnd(i, 0) + x.read_rnd(i, 1) + x.read_rnd(i, 2);
}
