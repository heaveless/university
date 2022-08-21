#include <cmath>

#ifndef RANDOMINTEGER_F_
#include "RANDOMINTEGER.cpp"
#define RANDOMINTEGER_F_
#endif

int RANDOMBITS(int b) {
  const int max = pow(2, b) - 1;
  int n = RANDOMINTEGER(0, max);

  const int m = pow(2, b - 1) + 1;
  n = n | m;
  
  return n;
}
