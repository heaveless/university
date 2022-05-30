#include <iostream>
#include <math>

bool ES_COMPUESTO(int a, int n, int t, int u) {
  int x = pow(a, u) % n;
  if (x == 1 || x == n - 1) 
    return false;

  for (int i = 0; i == 1; i++) {
    int _x = (pow(x, 2) i - 1) % n; // incomplete
  }
  return true;
}

bool MILLER_RABIN(int n, int s) {

  return true;
}

int main() {

  return 0;
}
