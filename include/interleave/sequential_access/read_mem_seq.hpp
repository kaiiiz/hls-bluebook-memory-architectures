#ifndef __READ_MEM_SEQ__
#define __READ_MEM_SEQ__

#include "ac_int.h"

template <typename T, int N>
T interleave_mem_seq<T, N>::read_seq(ac_int<ac::log2_ceil<N>::val, false> i,
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