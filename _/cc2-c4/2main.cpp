#include <iostream>

typedef bool Function(int, int);

bool ascend(int a, int b) { return a > b; }

bool descend(int a, int b) { return a < b; }

void bubble(int* source, int length, Function *func) {
  std::cout << func(1, 2) << std::endl;
}

int main() {
  int source[] = {1, 2, 3, 4, 5};
  bubble(source, 5, &descend);

  return 0;
}
