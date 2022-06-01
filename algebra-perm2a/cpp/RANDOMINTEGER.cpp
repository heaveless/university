#include <time.h>

int RANDOMINTEGER(int min, int max) {
  srand(time(0));
  const int positive = 1;
  return rand() % (max - min + positive) + min;
}

