#ifndef __SHIFT__
#define __SHIFT__
#include "ac_int.h"
template <typename T, int N>
class circular_shift {
 private:
  T mem[N];
  ac_int<ac::log2_ceil<N>::val + 1, false> wptr;
  ac_int<ac::log2_ceil<N>::val + 1, true> rptr;

 public:
  circular_shift() {
    T dummy;
    wptr = 0;
    rptr = 0;
    for (int i = 0; i < N; i++) mem[i] = dummy;
  }
  void operator<<(T data) {
    mem[wptr] = data;
    wptr++;
    if (wptr == N) wptr = 0;
  }
  T operator[](ac_int<ac::log2_ceil<N>::val, false> idx) {
    rptr = (wptr - 1 - idx);
    if (rptr < 0) rptr = rptr + N;
    return mem[rptr];
  }
};
#endif