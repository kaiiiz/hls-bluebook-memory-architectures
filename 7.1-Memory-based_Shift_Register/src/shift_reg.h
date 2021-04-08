#ifndef __SHIFT_REG_H__
#define __SHIFT_REG_H__

#define N_REGS 4

typedef int dType;

void shift_reg(dType din, dType dout[N_REGS]);
void circular_shift_reg(dType din, dType dout[N_REGS]);

#endif
