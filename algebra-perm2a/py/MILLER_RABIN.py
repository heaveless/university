#include "ES_COMPUESTO.cpp"

#ifndef STDINT_LIB_
#include <stdint.h>
#define STDINT_LIB_
#endif

#ifndef RANDOMINTEGER_F_
#include "RANDOMINTEGER.cpp"
#define RANDOMINTEGER_F_
#endif

bool MILLER_RABIN(int64_t n, int64_t s) {
  int64_t t = 0;
  int64_t u = n - 1;
  while (u % 2 == 0) {
    u = u / 2;
    t = t + 1;

    for (int j = 1; j < s; j++) {
      const int64_t a = RANDOMINTEGER(2, n - 1);
      if (ES_COMPUESTO(a, n, t, u))
        return false;
    }
  }

  return true;
}


