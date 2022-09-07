#include <iostream>

#include "sort.cpp"
#include "utils.cpp"

int main() {
  int length = 7;
  int* data = generate(length);
  print(data, length, "Base data");

  Algorithm::sortWithNothing(data, length);

  print(data, length, "Ordered data");

  return 0;
}
