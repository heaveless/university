#include <iostream>

int euclideExtend(int a, int b, int *x, int *y) {
  if (b ==0) {
    *x = 1;
    *y = 0;
    return a;
  }

  int _x;
  int _y;
  int mcd = euclideExtend(b, a % b, & _x, &_y);

  *x = _y;
  *y = _x - (a / b) * _y;

  return mcd;
}

int modulo(int a, int b) {
  return (a % b + b) % b;
}

int reverseModule(int a, int b, int *x, int *y) {
  int mcd = euclideExtend(a, b, x, y);
  if (mcd == 1)
    return modulo(*x, b);

  return 0;
}

int main() {
  int o = -40 % 121;
  int x, y, a = 13, m = 7;
  int i = reverseModule(a, m, &x, &y);
  if(i != 0) std::cout << "reverse: " << i << std::endl;

  return 0;
}

// crescent east - peiskos