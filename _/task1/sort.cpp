#include <time.h>

#define VALIDATE(a, b) (a > b)

enum AlgorithmType
{
  Nothing,
  Polymorphism,
  Function,
  Macro
};

class Algorithm
{
private:
  static void swap(int *a, int *b)
  {
    int tmp = *a;
    *a = *b;
    *b = tmp;
  }

  template <class T>
  static void sort(int *data, int length, T type, AlgorithmType algorithm = AlgorithmType::Nothing)
  {
    if (length == 1)
      return;

    for (int *ptr = data; ptr < data + length; ptr++)
    {
      int *next = ptr + 1;

      bool isValidate = false;

      switch (algorithm)
      {
      case AlgorithmType::Polymorphism:
        // isValidate = (*type).validate(ptr, next);
        break;
      case AlgorithmType::Function:
        // isValidate = (*type)(ptr, next);
      break;
      case AlgorithmType::Macro:
        isValidate = VALIDATE(*ptr, *next);
        break;
      default:
        isValidate = *ptr > *next;
        break;
      }

      if (isValidate)
        swap(ptr, next);
    }

    sort(data, --length, type, algorithm);
  }

public:
  static void sortWithNothing(int *data, int length)
  {
    sort(data, length, 0);
  }

  template <class T>
  static void sortWithPolymorphism(int *data, int length, T type)
  {
    sort(data, length, type, AlgorithmType::Polymorphism);
  }

  template <class T>
  static void sortWithFunction(int *data, int length, T type)
  {
    sort(data, length, type, AlgorithmType::Function);
  }

  static void sortWithMacro(int *data, int length)
  {
    sort(data, length, NULL, AlgorithmType::Macro);
  }
};
