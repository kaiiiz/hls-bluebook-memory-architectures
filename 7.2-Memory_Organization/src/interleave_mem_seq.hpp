#ifndef __INTERLEAVE_MEM_SEQ__
#define __INTERLEAVE_MEM_SEQ__

#define ADDRESS_BITWIDTH (16)

#include "ap_int.h"

template <typename T, int N>
class interleave_mem_seq {
 public:
  T x0[N / 3];
  T x1[N / 3];
  T x2[N / 3];
  ap_uint<ADDRESS_BITWIDTH> idx;
  ap_uint<2> sel;

 public:
  interleave_mem_seq() {
#pragma HLS RESOURCE variable = x0 core = RAM_1P_BRAM
#pragma HLS RESOURCE variable = x1 core = RAM_1P_BRAM
#pragma HLS RESOURCE variable = x2 core = RAM_1P_BRAM

	idx = 0;
    sel = 0;
  }

  void write_seq(ap_uint<ADDRESS_BITWIDTH> i, T x_in[N]);
  T read_seq(ap_uint<ADDRESS_BITWIDTH> i, int offset);
};
#include "read_mem_seq.hpp"
#include "write_mem_seq.hpp"

#endif
