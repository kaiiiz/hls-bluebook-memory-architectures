#include "ap_int.h"

void test_sp_orig(ap_uint<10> din[720], ap_uint<10> dout[720], bool write) {
#pragma HLS RESOURCE variable=din core=RAM_1P_BRAM
#pragma HLS RESOURCE variable=dout core=RAM_1P_BRAM

	static ap_uint<10> ram[720] = {0};
#pragma HLS RESOURCE variable=ram core=RAM_1P_BRAM

	for (int i = 0; i < 720; i++) {
#pragma HLS PIPELINE II=1
		dout[i] = ram[i];
		if (write) {
			ram[i] = din[i];
		}
	}
}
