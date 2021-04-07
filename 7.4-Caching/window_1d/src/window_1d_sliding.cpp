#include "shift_class.hpp"
#include "window_1d.h"

void clip_window(shift_class<ap_uint<8>, 3> shift_reg,
                 int i, ap_uint<8> window[3]) {
    window[0] = (i == 1) ? shift_reg[1] : shift_reg[2];
    window[1] = shift_reg[1];
    window[2] = (i == NUM_WORDS) ? shift_reg[1] : shift_reg[0];
}

// I = 1: shift[0]: d1, shift[1]: d0, shift[2]: x
// I = 2: shift[0]: d2, shift[1]: d1, shift[2]: d0

// take advantage of array access patterns in order to reduce
// the memory access of "din" to once per clock cycle
void window_avg(ap_uint<8> din[NUM_WORDS],
                ap_uint<8> dout[NUM_WORDS]) {
    const ap_ufixed<3, 1> coeffs[3] = {0.25, 0.5, 0.25};
    // shift registers with three taps, store previous values of "din"
    shift_class<ap_uint<8>, 3> shift_reg;
    // apply the boundary conditions to the sliding shift register
    ap_uint<8> window[3];
    ap_ufixed<13, 11> mac;
    ap_uint<8> din_tmp;

COMP:
    // NUM_WORDS + 1 : "dout[0]" requires additional two reads from "din"
    for (int i = 0; i != NUM_WORDS + 1; i++) {
#pragma HLS PIPELINE II=1
        if (i < NUM_WORDS)  //prevent overread of din
            din_tmp = din[i];
        shift_reg << din_tmp;
        clip_window(shift_reg, i, window);
        mac = window[0] * coeffs[0] + window[1] * coeffs[1] + window[2] * coeffs[2];
        if (i >= 1)  //startup
            dout[i - 1] = mac.to_int();
    }
}
