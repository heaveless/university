#include "ES_COMPUESTO.cpp"

#ifndef RANDOMINTEGER_F_
#include "RANDOMINTEGER.cpp"
#define RANDOMINTEGER_F_
#endif

bool MILLER_RABIN(int n, int s) {
  int t = 0;
  int u = n - 1;
  while (u % 2 == 0) {
    u = u / 2;
    t = t + 1;

    for (int j = 1; j < s; j++) {
      const int a = RANDOMINTEGER(2, n - 1);
      if (ES_COMPUESTO(a, n, t, u))
        return false;
    }
  }

  return true;
}


