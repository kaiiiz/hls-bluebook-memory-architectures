#include "include/shift/shift_reg.h"
void shift_reg(dType din, dType dout[N_REGS]) {
  static dType regs[N_REGS];
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