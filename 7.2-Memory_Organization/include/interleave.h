#ifndef __INTERLEAVE_H__
#define __INTERLEAVE_H__

#define NUM_WORDS 9
#include "ac_int.h"

void interleave(ac_int<8> x_in[NUM_WORDS], ac_int<8> y[NUM_WORDS / 3],
                bool load);
void interleave_manual_rnd(ac_int<8> x_in[NUM_WORDS], ac_int<8> y[NUM_WORDS / 3],
                       bool load);
void interleave_manual_seq(ac_int<8> x_in[NUM_WORDS], ac_int<8> y[NUM_WORDS / 3],
                       bool load);



#endif