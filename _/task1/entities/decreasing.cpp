#ifndef DECREASING_CLASS_
#define DECREASING_CLASS_

#include "sort-type.cpp"

class Decreasing : public SortType {
  public:
    bool validate(int* a, int* b) {
      return *a > *b;
    }
};

#endif
