#include "RANDOMBITS.cpp"

#ifndef MILLER_RABIN_F_
#include "MILLER_RABIN.cpp"
#define MILLER_RABIN_F_
#endif

int RANDOMGEN_PRIMOS(int b) {
  int s = 0;
  int n = RANDOMBITS(b);

  while (!MILLER_RABIN(n, s))
    n += 2;
  
  return n;
}
