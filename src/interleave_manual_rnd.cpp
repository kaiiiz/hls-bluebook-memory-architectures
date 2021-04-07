#include "include/interleave/interleave.h"
#include "include/interleave/random_access/interleave_mem_rnd.hpp"

void interleave_manual_rnd(ac_int<8> x_in[NUM_WORDS],
                           ac_int<8> y[NUM_WORDS / 3], bool load) {
  static interleave_mem_rnd<ac_int<8>, NUM_WORDS> x;
  int idx = 0;

  if (load)
    for (int i = 0; i < NUM_WORDS; i += 1) x.write_rnd(i, x_in);
  else
    for (int i = 0; i < NUM_WORDS; i += 3)
      y[idx++] = x.read_rnd(i, 0) + x.read_rnd(i, 1) + x.read_rnd(i, 2);
}