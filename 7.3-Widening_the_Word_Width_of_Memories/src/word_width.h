#ifndef __WORD_WIDTH__
#define __WORD_WIDTH__

#define NUM_WORDS (9)

#include "ap_int.h"

void word_width(ap_int<8> x_in[NUM_WORDS], ap_int<8> y[NUM_WORDS / 3],
                bool load);
                
void word_width_manual(ap_int<8> x_in[NUM_WORDS], ap_int<8> y[NUM_WORDS / 3],
                bool load);

#endif
