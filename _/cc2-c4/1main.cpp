#include <iostream>

class Operacion {
  public:
    int data;

    int sum(int a, int b) {
      return a + b;
    }

    int multiplication(int a, int b) {
      return a * b;
    }

    int subtraction(int a, int b) {
      return a - b;
    }
};

typedef int(Operacion::*tpm)(int, int);
typedef void Function(int* a, int size);

int call(int a, int b, Operacion *op, int(Operacion::*pm)(int, int)) {
  return (*op.*pm)(a, b);
  // return (op->*pm)(a, b);
}

int callWithType(int a, int b, Operacion *op, tpm pm) {
  return (*op.*pm)(a, b);
}

// int callAllFunctions(int a, int b, Operacion *op, tpm* pm, int size) {
// // for (tpm* f = pm; f < pm + size; f++) {
//     std::cout << "a";
//   // }
//   return 0;
// }

void bubble(int* a, int size) {}

void print() {}

int main() {
  Operacion o;
  int(Operacion::*p)(int, int);
  p = &Operacion::sum;
  int case1 = (o.*p)(5, 4);
  int case2 = o.sum(5, 4);
  int case3 = call(3, 7, &o, &Operacion::multiplication);
  int case4 = callWithType(3, 7, &o, &Operacion::multiplication);

  int size = 3;
  tpm input5[3] = { &Operacion::sum, &Operacion::multiplication, &Operacion::subtraction }; 
  
  // test code
  for (size_t i = 0; i < size; i++) {
    int testCase = (o.*input5[i])(2, 5);
    std::cout << testCase << std::endl;
  }  
  // end test code

  // callAllFunctions(2, 5, &o, input5, size);

  std::cout << case1 << std::endl;
  std::cout << case2 << std::endl;
  std::cout << case3 << std::endl;
  std::cout << case4 << std::endl;

  // experimental case

  // std::cout << typeid(Operacion::multiplication).name() << std::endl;
  return 0;
}

