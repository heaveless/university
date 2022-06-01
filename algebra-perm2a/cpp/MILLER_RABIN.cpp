#include "RANDOMINTEGER.cpp"
#include "ES_COMPUESTO.cpp"

bool MILLER_RABIN(int n, int s) {
  int t = 0;
  int u = n - 1;
  while (u % 2 == 0) {
    u = u / 2;
    t = t + 1;

    for (int j = 1; j < s; j++) {
      const int a = RANDOMINTEGER(2, n - 1);
      if (ES_COMPUSTO(a, n, t, u))
        return false;
    }
  }

  return true;
}


