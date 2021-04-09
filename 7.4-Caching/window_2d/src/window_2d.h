#ifndef __WINDOW_2D__
#define __WINDOW_2D__

#include "ap_int.h"

#define NUM_ROW 480
#define NUM_COL 720

void avg(ap_uint<8> din[NUM_ROW][NUM_COL], ap_uint<8> dout[NUM_ROW][NUM_COL]);

void window_avg(ap_uint<8> din[NUM_ROW][NUM_COL], ap_uint<8> dout[NUM_ROW][NUM_COL]);

#endif
