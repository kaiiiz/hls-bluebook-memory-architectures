#ifndef __WRITE_MEM_SEQ__
#define __WRITE_MEM_SEQ__

#include "ac_int.h"
template <typename T, int N>
void interleave_mem_seq<T, N>::write_seq(ac_int<ac::log2_ceil<N>::val, false> i,
                                         T x_in[N]) {
  int tmp = x_in[i];
  switch (sel++) {
    case 0:
      x0[idx] = tmp;
      break;
    case 1:
      x1[idx] = tmp;
      break;
    case 2:
      x2[idx] = tmp;
      break;
  }

  if (idx == N / 3) idx = 0;
  if (sel == 3) sel = 0;
}

#endif