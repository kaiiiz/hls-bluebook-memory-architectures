#include <iostream>
#include <cstdlib>
#include "../src/window_2d.h"
#include "ap_int.h"
#include "ap_fixed.h"

using namespace std;

static inline int clip(int i) {
    int tmp = i;
    if (tmp < 0)
        tmp = 0;
    else if (tmp > NUM_ROW - 1)
        tmp = NUM_ROW - 1;
    return tmp;
}

int main(int argc, char *argv[]) {
	ap_uint<8> din[NUM_ROW][NUM_COL];
	ap_uint<8> dout[NUM_ROW][NUM_COL];
	ap_uint<8> answer[NUM_ROW][NUM_COL];

	for (int r = 0; r != NUM_ROW; r++) {
		for (int c = 0; c != NUM_COL; c++) {
			din[r][c] = rand();
		}
	}

    ap_ufixed<13, 11> tmp;
    ap_ufixed<3, 1> coeffs[3] = {0.25, 0.5, 0.25};
	for (int r = 0; r != NUM_ROW; r++) {
		for (int c = 0; c != NUM_COL; c++) {
			tmp = din[clip(r - 1)][c] * coeffs[0] + din[r][c] * coeffs[1] + din[clip(r + 1)][c] * coeffs[2];
			answer[r][c] = tmp.to_uint();
		}
	}

	window_avg(din, dout);

	int pass = 1;
	for (int r = 0; r != NUM_ROW; r++) {
		for (int c = 0; c != NUM_COL; c++) {
			cout << "dout[" << r << "][" << c << "]: " << dout[r][c] << \
					", answer[" << r << "][" << c << "]: " << answer[r][c] << "\n";
			if (dout[r][c] != answer[r][c]) {
				pass = 0;
			}
		}
	}

	if(!pass) {
		cout << ">> Test failed!" << endl;
		return 1;
	}

	cout << ">> Test passed!" << endl;
	cout << "------------------------" << endl;
	return 0;
}

