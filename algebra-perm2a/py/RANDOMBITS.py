#include <cmath>

#ifndef STDINT_LIB_
#include <stdint.h>
#define STDINT_LIB_
#endif

#ifndef RANDOMINTEGER_F_
#include "RANDOMINTEGER.cpp"
#define RANDOMINTEGER_F_
#endif

int64_t RANDOMBITS(int64_t b) {
  const int64_t max = pow(2, b) - 1;
  int64_t n = RANDOMINTEGER(0, max);
  std::cout << n << std::endl;
  const int64_t m = pow(2, b - 1) + 1;
  n = n | m;
  
  return n;
}
