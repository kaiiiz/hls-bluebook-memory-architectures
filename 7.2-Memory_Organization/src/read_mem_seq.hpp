#ifndef __READ_MEM_SEQ__
#define __READ_MEM_SEQ__

#include "ap_int.h"

template <typename T, int N>
T interleave_mem_seq<T, N>::read_seq(ap_uint<ADDRESS_BITWIDTH> i,
                                     int offset) {
  T tmp = 0;
  switch (offset) {
    case 0:
      tmp = x0[i];
      break;
    case 1:
      tmp = x1[i];
      break;
    case 2:
      tmp = x2[i];
      break;
  }

  return tmp;
}

#endif
