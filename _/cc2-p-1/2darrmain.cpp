#include <iostream>

int main() {
  int x = 2, y = 3, z = 4;

  int*** m = new int**[x];

  for (int*** p = m; p < m + x; p++) {
    *p = new int*[y];
    for (int** q = *p; q < *p + y; q++) {
      *q = new int[z];
      for (int* r = *q; r < *q + z; r++) {
        *r = 5;
        std::cout << *r;
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

  for (int*** p = m; p < m + x; p++) {
    for (int** q = *p; q < *p + y; q++) {
      delete[] *q;
    }
    delete[] *p;
  }
  delete[] m;
  m = NULL;
}
