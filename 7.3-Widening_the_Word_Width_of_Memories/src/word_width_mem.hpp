#ifndef __WORD_WIDTH_MEM__
#define __WORD_WIDTH_MEM__

#define ADDRESS_BITWIDTH (16)

#include "ap_int.h"

template<int W, int N>
class word_width_mem {
  private:
  ap_uint<W*3> x[N/3];
  ap_uint<ADDRESS_BITWIDTH> idx;
  ap_uint<2> sel_rd;
  ap_uint<2> sel_wr;
  ap_uint<W*3> write3;
  ap_uint<W*3> read3;

  public:
  word_width_mem():sel_rd(0), sel_wr(0){
#pragma HLS RESOURCE variable=x core=RAM_1P_BRAM
  }
  void write(ap_uint<ADDRESS_BITWIDTH> i, ap_int<W> x_in[N]);
  ap_int<W> read(ap_uint<ADDRESS_BITWIDTH> i, const int offset);
};
#include "ww_read_mem.hpp"
#include "ww_write_mem.hpp"

#endif
