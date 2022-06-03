#include "RANDOMBITS.cpp"

#ifndef STDINT_LIB_
#include <stdint.h>
#define STDINT_LIB_
#endif

#ifndef MILLER_RABIN_F_
#include "MILLER_RABIN.cpp"
#define MILLER_RABIN_F_
#endif

int64_t RANDOMGEN_PRIMOS(int64_t b) {
  int64_t s = 0;
  int64_t n = RANDOMBITS(b);
  // std::cout << n << std::endl;
  while (!MILLER_RABIN(n, s))
    n += 2;
  
  return n;
}
