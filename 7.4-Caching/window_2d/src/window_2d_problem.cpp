#include "ap_int.h"
#include "ap_fixed.h"

int clip(int i) {
    int tmp = i;
    if (tmp < 0)
        tmp = 0;
    else if (tmp > 480 - 1)
        tmp = 480 - 1;
    return tmp;
}

void avg(ap_uint<8> din[480][720], ap_uint<8> dout[480][720]) {
#pragma HLS RESOURCE variable=din core=RAM_1P_BRAM
#pragma HLS RESOURCE variable=dout core=RAM_1P_BRAM
    const ap_ufixed<3, 1> coeffs[3] = {0.25, 0.5, 0.25};
    ap_ufixed<13, 11> tmp;

ROW:
    for (int r = 0; r != 480; r++) {
    COL:
        for (int c = 0; c != 720; c++) {
#pragma HLS PIPELINE II=1
            tmp = din[clip(r - 1)][c] * coeffs[0] + din[r][c] * coeffs[1] + din[clip(r + 1)][c] * coeffs[2];
            dout[r][c] = tmp.to_int();
        }
    }
}
