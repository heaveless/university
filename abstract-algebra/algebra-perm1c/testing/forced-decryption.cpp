#include <iostream>
#include <stdexcept>

void app(int a, int n) {
  if (n < 0)
    throw std::invalid_argument("The n argument accepts only positive numbers.");

  
}

int main() {
  return 0;
}