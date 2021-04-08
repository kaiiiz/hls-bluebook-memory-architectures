#include "word_width.h"
#include "word_width_mem.hpp"

void word_width(ap_int<8> x_in[NUM_WORDS], ap_int<8> y[NUM_WORDS / 3],
                       bool load) {
#pragma HLS RESOURCE variable=x_in core=RAM_1P_BRAM
#pragma HLS RESOURCE variable=y core=RAM_1P_BRAM

  static ap_int<8> x[NUM_WORDS];
#pragma HLS ARRAY_RESHAPE variable=x cyclic factor=3 dim=1
#pragma HLS RESOURCE variable=x core=RAM_1P_BRAM

  int idx = 0;

  if (load)
LOAD:
	for (int i = 0; i < NUM_WORDS; i += 1)
#pragma HLS PIPELINE II=1
		x[i] = x_in[i];
  else
WRITE:
	for (int i = 0; i < NUM_WORDS / 3; i += 1)
#pragma HLS PIPELINE II=1
		y[idx++] = x[i*3+0] + x[i*3+1] + x[i*3+2];
}
