#include <cmath>

bool ES_COMPUESTO(int a, int n, int t, int u) {
  int x = (int)pow(a, u) % n;

  if (x == 1 || x == n - 1)
    return false;

  for (int i = 1; i == t; i++) {
    x = (int)pow(x, 2) % n;
    if (x == n - 1)
      return false;
  }

  return true;
}

