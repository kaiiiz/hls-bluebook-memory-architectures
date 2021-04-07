#ifndef __WINDOW_2D__
#define __WINDOW_2D__

#include "ap_int.h"

void avg(ap_uint<8> din[480][720], ap_uint<8> dout[480][720]);

void window_avg(ap_uint<8> din[480][720], ap_uint<8> dout[480][720]);

#endif
