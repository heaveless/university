#include <iostream>

int main() {
  int f = 3;
  int c = 2;

  int **M = new int*[f];
  for(int i = 0; i < f; i++) {
    M[i] = new int [c];
    M[i][0] = 5;
  }

  for (int i = 0; i < f; i++) {
    delete[] M[i];
  }

  delete[] M;

  return 0;
}
