#ifndef __WRITE_MEM_RND__
#define __WRITE_MEM_RND__

#include "ap_int.h"

template <typename T, int N>
void interleave_mem_rnd<T, N>::write_rnd(ap_uint<ADDRESS_BITWIDTH> i,
                                 T x_in[N]) {
  T tmp = x_in[i];
  switch (i % 3) {
    case 0:
      x0[i / 3] = tmp;
      break;
    case 1:
      x1[i / 3] = tmp;
      break;
    case 2:
      x2[i / 3] = tmp;
      break;
  }
}

#endif
