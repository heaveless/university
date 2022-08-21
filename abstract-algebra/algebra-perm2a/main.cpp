#include <iostream>
#include "cpp/GEN_PRIMOS.cpp"
#include "cpp/RANDOMGEN_PRIMOS.cpp"

void allPrimeNumber() {
  std::cout << __func__ << std::endl;

  int source[] = { 3, 4, 5 };
  int length = sizeof(source) / sizeof(*source);

  for (int* i = source; i < source + length; i++) {
    int prime = GEN_PRIMOS(*i);
    std::cout << prime << std::endl;
  }
}

void randomPrimeNumber() {
  std::cout << __func__ << std::endl;

  int source[] = { 
    16, 16, 16,
    32, 32, 32,
    64, 64, 64, 64
  };

  int length = sizeof(source) / sizeof(*source);

  for (int* i = source; i < source + length; i++) {
    int prime = RANDOMGEN_PRIMOS(*i);
    std::cout << prime << std::endl;
  }
}

int main() {
  allPrimeNumber();
  randomPrimeNumber();

  return 0;
}
