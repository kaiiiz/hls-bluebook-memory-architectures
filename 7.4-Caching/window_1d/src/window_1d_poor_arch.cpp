#include "window_1d.h"

int clip(int i) {
    int tmp = i;
    if (tmp < 0)
        tmp = 0;
    else if (tmp > NUM_WORDS - 1)
        tmp = NUM_WORDS - 1;
    return tmp;
}

// can compute a new valud of "dout[i]" every clock cycle
// but the coding style limits the design performance due to a memory bottleneck
void avg(ap_uint<8> din[NUM_WORDS], ap_uint<8> dout[NUM_WORDS]) {
#pragma HLS RESOURCE variable=din core=RAM_1P_BRAM
#pragma HLS RESOURCE variable=dout core=RAM_1P_BRAM

    const ap_ufixed<3, 1> coeffs[3] = {0.25, 0.5, 0.25};
    ap_ufixed<13, 11> tmp;

COMP:
    for (int i = 0; i != NUM_WORDS; i++) {
#pragma HLS PIPELINE II=1
        tmp = din[clip(i - 1)] * coeffs[0] + din[i] * coeffs[1] + din[clip(i + 1)] * coeffs[2];
        dout[i] = tmp.to_int();
    }
}
