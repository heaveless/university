#include "RANDOMBITS.cpp"
#include "MILLER_RABIN.cpp"

int RANDOMGEN_PRIMOS(int b) {
  int s = 0;
  const int n = RANDOMBITS(b);

  while (!MILLER_RABIN(n, s))
    n += 2
  
  return n;
}
