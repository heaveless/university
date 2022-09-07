#include <iostream>

#include "sort.cpp"
#include "utils.cpp"

#include "entities/decreasing.cpp"
#include "entities/increasing.cpp"
#include "entities/sort-type.cpp"

void test1() {
  int length = 7;
  int* data = generate(length);
  print(data, length);

  Algorithm::sortWithNothing(data, length);

  print(data, length, "Ordered data with nothing");
}

void test2() {
  int length = 7;
  int* data = generate(length);
  print(data, length);

  SortType* sortType = new Increasing();

  Algorithm::sortWitPolymorphism(data, length, sortType);

  print(data, length, "Ordered data with polymorphism");
}

void test3() {
  int length = 7;
  int* data = generate(length);
  print(data, length);

  Algorithm::sortWithNothing(data, length);

  print(data, length, "Ordered data with function");
}

void test4() {
  int length = 7;
  int* data = generate(length);
  print(data, length);

  Algorithm::sortWithNothing(data, length);

  print(data, length, "Ordered data with macro");
}

int main() {

  // test1();
  test2();
  //stest3();
  //test4();

  return 0;
}
