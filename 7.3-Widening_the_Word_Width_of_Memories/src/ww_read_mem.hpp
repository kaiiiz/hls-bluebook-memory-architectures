#ifndef __WW_READ_MEM__
#define __WW_READ_MEM__

#include "ap_int.h"

template <int W, int N>
ap_int<W> word_width_mem<W, N>::read(ap_uint<ADDRESS_BITWIDTH> i,
                                     const int offset) {

	// Force the call of function being merged
	// into the FSM of WRITE.
	// Critical Path will be too long,
	// but II = 1 is possible
#pragma HLS INLINE


	ap_int<W> tmp = 0;

  if (sel_rd++ == 0)  // read once every 3 calls
    read3 = x[i];

  if (sel_rd == 3) sel_rd = 0;

  switch (offset) {
    case 0:
      tmp = read3(W - 1, 0);
      break;
    case 1:
      tmp = read3(W * 2 - 1, W);
      break;
    case 2:
      tmp = read3(W * 3 - 1, W * 2);
      break;
  }

  return tmp;
}

#endif
