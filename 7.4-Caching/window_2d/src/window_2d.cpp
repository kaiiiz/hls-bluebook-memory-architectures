#include "ap_int.h"
#include "ap_fixed.h"
#include "window_2d.h"
#include "singleport_ram.hpp"

#include <iostream>
using namespace std;

void clip_window(int r, ap_uint<8> window[3]) {
    ap_uint<8> w[3];
    for (int i = 0; i < 3; i++)
        w[i] = window[i];
    window[0] = (r == 1) ? w[1] : w[0];
    window[1] = w[1];
    window[2] = (r == NUM_ROW) ? w[1] : w[2];
}

// arguments:
//      din: input
//      c: current address or column position
//      window: column aligned data
void buffer(ap_uint<8> din, int c, ap_uint<8> window[3]) {
    static singleport_ram<NUM_COL, 8> buffer0;
    static singleport_ram<NUM_COL, 8> buffer1;
    ap_uint<8> t0, t1;
    // one bit counter that is used to select between the two line buffers
    static ap_uint<1> sel = 1;
    // check current address or column position "c" and increments "sel" at the
    // start of a new row
    if (c == 0)  //switch buffer write at start of line
        sel++;
    // The input data "din" is passed to both memories along with the address "c"
    // "sel" is only active for one memory at a time so only one of the memories is written.
    t1 = buffer1.exec(din, c, sel);
    t0 = buffer0.exec(din, c, !sel);

    window[0] = (sel == 1) ? t1 : t0;
    window[1] = (sel == 1) ? t0 : t1;
    window[2] = din;
}

void window_avg(ap_uint<8> din[NUM_ROW][NUM_COL], ap_uint<8> dout[NUM_ROW][NUM_COL]) {
#pragma HLS RESOURCE variable=din core=RAM_1P_BRAM
#pragma HLS RESOURCE variable=dout core=RAM_1P_BRAM
    const ap_ufixed<3, 1> coeffs[3] = {0.25, 0.5, 0.25};
    ap_fixed<13, 11> tmp;
    ap_uint<8> w[3];
    ap_uint<8> din_tmp;
ROW:
    // first two rows must be read (r == 0 and r == 1) before there is
    // enough data to start computing the output
    for (int r = 0; r != NUM_ROW + 1; r++) {
    COL:
        for (int c = 0; c != NUM_COL; c++) {
#pragma HLS PIPELINE II=1
            if (r != NUM_ROW)
                din_tmp = din[r][c];
            buffer(din_tmp, c, w);
            clip_window(r, w);
            tmp = w[0] * coeffs[0] + w[1] * coeffs[1] + w[2] * coeffs[2];
            if (r != 0)
                dout[r - 1][c] = tmp.to_uint();
        }
    }
}
