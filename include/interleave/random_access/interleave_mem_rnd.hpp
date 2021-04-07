#ifndef __INTERLEAVE_MEM_RND__
#define __INTERLEAVE_MEM_RND__

#include "ac_int.h"
template <typename T, int N>
class interleave_mem_rnd {
  T x0[N / 3];
  T x1[N / 3];
  T x2[N / 3];

 public:
  interleave_mem_rnd() {}
  void write_rnd(ac_int<ac::log2_ceil<N>::val, false> i, T x_in[N]);
  T read_rnd(ac_int<ac::log2_ceil<N>::val, false> i, int offset);
};
#include "read_mem_rnd.hpp"
#include "write_mem_rnd.hpp"

#endif