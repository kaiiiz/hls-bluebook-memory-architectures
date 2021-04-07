#include <iostream>
#include "singleport_ram.hpp"

using namespace std;

int main(int argc, char *argv[]) {
	ap_uint<10> din1[360];
	ap_uint<10> din2[360];
	ap_uint<10> dout[360];
    static singleport_ram<360, 10> ram;

	int pass = 1;

	for (int i = 0; i < 360; i++) {
		din1[i] = i;
		din2[i] = i * 2;
	}

    for (int i = 0; i < 360; i++) {
    	ram.exec(din1[i], i, true);
    }

    // check din1
	cout << "---------Check din1---------" << endl;
    for (int i = 0; i < 360; i++) {
        dout[i] = ram.exec(din2[i], i, true);
    }

	for (int i = 0; i < 360; i++) {
		cout << "dout[" << i << "]: " << dout[i] << "\n";
		if (dout[i] != i) {
			pass = 0;
		}
	}

	// check din2
	cout << "---------Check din2---------" << endl;
    for (int i = 0; i < 360; i++) {
        dout[i] = ram.exec(din2[i], i, true);
    }

	for (int i = 0; i < 360; i++) {
		cout << "dout[" << i << "]: " << dout[i] << "\n";
		if (dout[i] != i * 2) {
			pass = 0;
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

