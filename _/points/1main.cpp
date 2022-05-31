#include <iostream>
#include <stdio.h>

class Operator {
  public:
    Operator() {}

    int sum(int a, int b) {
      this->print(__func__, a, b); 
      return a + b; 
    }
    
    int subtraction(int a, int b) { 
      this->print(__func__, a, b); 
      return a - b; 
    }
    
    int multiplication(int a, int b) { 
      this->print(__func__, a, b); 
      return a * b; 
    }
    
    int division(int a, int b) { 
      this->print(__func__, a, b); 
      return a / b; 
    }

    void print(const char* str, int a, int b) { 
      printf("%s(%i,%i): ", str, a, b); 
    }
};

template<class T>
struct Func {
  typedef int (T::*Type)(int, int);
};

struct Input {
  int a;
  int b;
};

template<class T>
T** genSource(int length) {
  T** source = new T*[length];

  for (T** ptr = source; ptr < source + length; ptr++) {
    *ptr = new T();
  }

  return source;
}
template<class T, typename F>
int runMethods(T* instance, F* method, int length, Input input) {
  int accumulator = 0;

  for (auto ptr = method; ptr < method + length; ptr++) {
    int result = (instance->**ptr)(input.a, input.b);
    accumulator += result;
    std::cout << result << "\t\t";
  }

  return accumulator;
}

int main() {
  int classLength = 3;
  int funcLength = 4;
  Input input = { 5, 6 };
  
  Operator** op = genSource<Operator>(classLength);

  Func<Operator>::Type methods[] = { 
    &Operator::sum, 
    &Operator::subtraction, 
    &Operator::multiplication, 
    &Operator::division 
  };

  for (Operator** ptr = op; ptr < op + classLength; ptr++) {
    int idx = ptr - op;
    printf("op[%i] -> ", idx);
    int result = runMethods(*op, methods, funcLength, input);
    printf("-> %i\n", result);
  }

  return 0;
}
