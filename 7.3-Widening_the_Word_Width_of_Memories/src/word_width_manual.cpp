#include "word_width.h"
#include "word_width_mem.hpp"

void word_width_manual(ap_int<8> x_in[NUM_WORDS], ap_int<8> y[NUM_WORDS / 3],
                       bool load) {
  static word_width_mem<8, NUM_WORDS> x;

  int idx = 0;

  if (load)
    for (int i = 0; i < NUM_WORDS; i += 1) x.write(i, x_in);
  else
    for (int i = 0; i < NUM_WORDS / 3; i += 1)
      y[idx++] = x.read(i, 0) + x.read(i, 1) + x.read(i, 2);
}
