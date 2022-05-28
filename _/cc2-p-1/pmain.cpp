#include <iostream>

int main() {
    int f = 3;
    int c = 2;

    int** M = new int*[f];
    for(int** p = M;p < M + f;p++) {
      *p = new int[c];
    }

    for (int** p = M; p < M + f; p++) {
      for (int* q = *p; q < (*p + c); q++) {
        *q = 5;
        std::cout << *q << ",";
      }
      std::cout << "\n";
    }

    for (int** p = M; p < M + f; p++) {
      delete[] *p;
    }

    delete[] M;

    return 0;
}
