#include <time.h>

#define VALIDATE(a, b) (a > b)

class Algorithm
{
private:
  static void swap(int *a, int *b)
  {
    int tmp = *a;
    *a = *b;
    *b = tmp;
  }

public:
  static void sortWithNothing(int *data, int length)
  {
    if (length == 1)
      return;

    for (int *ptr = data; ptr < data + length; ptr++)
    {
      int *next = ptr + 1;

      if (*ptr > *next)
        swap(ptr, next);
    }

    sortWithNothing(data, --length);
  }

  template <class T>
  static void sortWithPolymorphism(int *data, int length, T type)
  {
    if (length == 1)
      return;

    for (int *ptr = data; ptr < data + length; ptr++)
    {
      int *next = ptr + 1;

      if ((*type).validate(ptr, next))
        swap(ptr, next);
    }

    sortWithPolymorphism(data, --length, type);
  }

  template <class T>
  static void sortWithFunction(int *data, int length, T type)
  {
    if (length == 1)
      return;

    for (int *ptr = data; ptr < data + length; ptr++)
    {
      int *next = ptr + 1;

      if ((*type)(ptr, next))
        swap(ptr, next);
    }

    sortWithFunction(data, --length, type);
  }

  static void sortWithMacro(int *data, int length)
  {
    if (length == 1)
      return;

    for (int *ptr = data; ptr < data + length; ptr++)
    {
      int *next = ptr + 1;

      if (VALIDATE(*ptr, *next))
        swap(ptr, next);
    }

    sortWithMacro(data, --length);
  }
};
