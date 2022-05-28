#include <iostream>

int main() {
  int x = 2, y = 3, z = 4;

  int*** m = new int**[x];

  for (int*** p = m; p < m + x; p++) {
    *p = new int*[y];
    std::cout << typeid(p).name();
    for (int** q = *p; q < *p + y; q++) {
      *q = new int[z];
      std::cout << q;
      for (int* r = *q; r < *q + z; r++) {
        *r = 5;
        std::cout << "r";
      }
    }
  }

  std::cout << std::endl;


  for (int*** p = m; p < m + x; p++) {
    for (int** q = *p; q < *p + y; q++) {
      for (int* r = *q; r < *q + z; r++) {
        std::cout << *r;
      }
    }
  }



  // int* m = **d3 + 0;
  //
  // for (int* i = m; i < m + (x * y * z); i++) {
  //   std::cout << *i << " ";
  // }
  //
  // std::cout << ***d3;
}
