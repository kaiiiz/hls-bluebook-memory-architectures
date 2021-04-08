#include "shift_reg.h"
#include "circular_shift.h"

void shift_reg(dType din, dType dout[N_REGS]) {

  static dType regs[N_REGS];
#pragma HLS RESOURCE variable=regs core=RAM_1P_BRAM

SHIFT:
  for (int i = N_REGS - 1; i >= 0; i--) {
    if (i == 0)
      regs[i] = din;
    else
      regs[i] = regs[i - 1];
  }

WRITE:
  for (int i = 0; i < N_REGS; i++) {
    dout[i] = regs[i];
  }
}

void circular_shift_reg(dType din, dType dout[N_REGS]) {

  static circular_shift<dType, N_REGS> regs;

SHIFT:
  regs << din;

WRITE:
  for (int i = 0; i < N_REGS; i++) {
	dout[i] = regs[i];
  }
}
