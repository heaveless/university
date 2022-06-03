#include <time.h>

#ifndef STDINT_LIB_
#include <stdint.h>
#define STDINT_LIB_
#endif

int64_t RANDOMINTEGER(int64_t min, int64_t max) {
  srand(time(0));
  const int64_t positive = 1;
  return rand() % (max - min + positive) + min;
}

