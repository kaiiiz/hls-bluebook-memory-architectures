#include "include/interleave/interleave.h"

#define USE_AUTO_PARTITION 0


void interleave(ac_int<8> x_in[NUM_WORDS], ac_int<8> y[NUM_WORDS / 3],
                bool load) {
  
  static ac_int<8> x[NUM_WORDS];
  int idx = 0;

#if USE_AUTO_PARTITION
#pragma HLS array_partition variable = x
#endif

  if (load)
    for (int i = 0; i < NUM_WORDS; i += 1) x[i] = x_in[i];
  else
    for (int i = 0; i < NUM_WORDS; i += 3)
      y[idx++] = x[i] + x[i + 1] + x[i + 2];
}