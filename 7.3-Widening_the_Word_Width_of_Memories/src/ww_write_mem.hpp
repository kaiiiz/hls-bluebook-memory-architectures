#ifndef __WW_WRITE_MEM__
#define __WW_WRITE_MEM__

#include "ap_int.h"

template <int W, int N>
void word_width_mem<W, N>::write(ap_uint<ADDRESS_BITWIDTH> i,
                                 ap_int<W> x_in[N]) {
  write3(sel_wr * W + W - 1, sel_wr * W) = x_in[i](W-1, 0);

  sel_wr++;

  if (sel_wr == 3) {
    x[idx++] = write3;
    sel_wr = 0;
  }

  if (idx == N / 3) {
    idx = 0;
  }
}

#endif
