#include "interleave.h"

void interleave(
		ap_int<8> x_in[NUM_WORDS],
		ap_int<8> y[NUM_WORDS / 3],
		bool load) {
  
  static ap_int<8> x[NUM_WORDS];
#pragma HLS RESOURCE variable=x core=RAM_1P_BRAM
#pragma HLS ARRAY_PARTITION variable=x cyclic factor=3 dim=1

  int idx = 0;

  if (load)
LOAD:
    for (int i = 0; i < NUM_WORDS; i += 1)
#pragma HLS PIPELINE II=1
    	x[i] = x_in[i];
  else
WRITE:
    for (int i = 0; i < NUM_WORDS; i += 3)
#pragma HLS PIPELINE II=1
    	y[idx++] = x[i] + x[i + 1] + x[i + 2];
}
