#ifndef __WINDOW_1D__
#define __WINDOW_1D__

#include <ap_int.h>
#include <ap_fixed.h>

#define NUM_WORDS 256

void avg(ap_uint<8> din[NUM_WORDS], ap_uint<8> dout[NUM_WORDS]);

void window_avg(ap_uint<8> din[NUM_WORDS], ap_uint<8> dout[NUM_WORDS]);

#endif
