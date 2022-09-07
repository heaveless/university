#ifndef INCREASING_CLASS_
#define INCREASING_CLASS_

#include "sort-type.cpp"
#include <iostream>
class Increasing : public SortType {
  public:
    bool validate(int* a, int* b) {
      return *a < *b;
    }
};

#endif
