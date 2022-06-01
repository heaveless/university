#include "MILLER_RABIN.cpp"

int GEN_PRIMOS(int n) {
  int s = 0;
  n = n + 1 - (n % 2);

  while (!MILLER_RABIN(n, s))
    n += 2;

  return n;
}
