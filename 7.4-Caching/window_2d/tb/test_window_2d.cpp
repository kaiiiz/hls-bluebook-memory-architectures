#include <iostream>
#include "window_2d.h"
#include "ap_int.h"
#include "ap_fixed.h"

using namespace std;

static inline int clip(int i) {
    int tmp = i;
    if (tmp < 0)
        tmp = 0;
    else if (tmp > 480 - 1)
        tmp = 480 - 1;
    return tmp;
}

int main(int argc, char *argv[]) {
	ap_uint<8> din[480][720];
	ap_uint<8> dout[480][720];
	ap_uint<8> answer[480][720];

	for (int r = 0; r != 480; r++) {
		for (int c = 0; c != 720; c++) {
			din[r][c] = ((r+1) * (c+1) + r + c) % 128;
		}
	}

    ap_ufixed<13, 11> tmp;
	float coeffs[3] = {0.25, 0.5, 0.25};
	for (int r = 0; r != 480; r++) {
		for (int c = 0; c != 720; c++) {
			tmp = din[clip(r - 1)][c] * coeffs[0] + din[r][c] * coeffs[1] + din[clip(r + 1)][c] * coeffs[2];
			answer[r][c] = tmp.to_int();
		}
	}

	window_avg(din, dout);

	int pass = 1;
	for (int r = 0; r != 480; r++) {
		for (int c = 0; c != 720; c++) {
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

