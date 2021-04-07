#ifndef __INTERLEAVE_MEM_SEQ__
#define __INTERLEAVE_MEM_SEQ__

#include "ac_int.h"
template <typename T, int N>
class interleave_mem_seq {
  T x0[N / 3];
  T x1[N / 3];
  T x2[N / 3];
  ac_int<ac::log2_ceil<N>::val, false> idx;
  ac_int<2, false> sel;

 public:
  interleave_mem_seq() {
    idx = 0;
    sel = 0;
  }

  void write_seq(ac_int<ac::log2_ceil<N>::val, false> i, T x_in[N]);
  T read_seq(ac_int<ac::log2_ceil<N>::val, false> i, int offset);
};
#include "read_mem_seq.hpp"
#include "write_mem_seq.hpp"

#endif