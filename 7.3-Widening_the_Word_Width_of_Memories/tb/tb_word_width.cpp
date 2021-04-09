#include <cstdio>
#include "../src/word_width.h"
#include "ap_int.h"
#include "cstdlib"

#define AUTO 0

int main(int argc, char **argv){

	ap_int<8> in[NUM_WORDS];
	ap_int<8> sw_out[NUM_WORDS/3];
	ap_int<8> hw_out[NUM_WORDS/3];

	// Generate Input
	for (int i=0; i<NUM_WORDS; i++)
		in[i] = rand()%300;

	// Generate sw_out
	for (int i=0; i<NUM_WORDS/3; i++)
		sw_out[i] = in[i*3] +
					in[i*3 + 1] +
					in[i*3 + 2] ;

	// Execution
#if AUTO
	word_width(in, hw_out, true);
	word_width(in, hw_out, false);
#else
	word_width_manual(in, hw_out, true);
	word_width_manual(in, hw_out, false);
#endif

	// Compare
	bool pass = true;
	for (int i=0; i<NUM_WORDS/3; i++){
		printf("sw= %d, hw= %d\n", sw_out[i].to_int(), hw_out[i].to_int());
		pass &= (sw_out[i] == hw_out[i]);
	}

	// Pass or Fail
	if (!pass){
		printf("Test Fail!\n");
		return -1;
	} else {
		printf("Test Pass!\n");
		return 0;
	}
}
