#include <iostream>

int main() {
  int x = 2, y = 3, z = 4;

  int* m = new int [z * y * x];

  for (int* p = m; p < m + (x * y * z); p++) {
    int idx = p - m;
    *p = 5;
    std::cout << *p << idx <<"-";
  }
}
