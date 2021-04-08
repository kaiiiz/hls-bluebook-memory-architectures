#ifndef __READ_MEM_RND__
#define __READ_MEM_RND__

#include "ap_int.h"

template <typename T, int N>
T interleave_mem_rnd<T, N>::read_rnd(ap_uint<ADDRESS_BITWIDTH> i,
                             int offset) {
  T tmp = 0;
  switch (offset) {
    case 0:
      tmp = x0[i / 3];
      break;
    case 1:
      tmp = x1[i / 3];
      break;
    case 2:
      tmp = x2[i / 3];
      break;
  }
  return tmp;
}

#endif
