#include <iostream>
#include <time.h>

int main()
{
  srand(time(0));

  int size = 10;
  int data[size];// = { 90, 45, 30, 20, 10, 40, 60, 50, 5, 2 }; //caso de prueba manual
  
  // generamos datos aleatorios
  std::cout << "Antes de ordenar: " << std::endl;
  for(int* e = data; e < data + size; e++) {
    *e = rand() & 100; // comentar linea para caso de prueba manual
    std::cout << *e << " ";
  }

  std::cout << "\n\nciclo: {ciclo} -> item = {antes del cambio} {despues del cambio}" << std::endl;

  for(int* cycleStart = data; cycleStart < data + (size - 1); cycleStart++) {
    // inicializamos el valor del primer elemento
    int element = *cycleStart;
    int* pointer = cycleStart;

    // Cuenta todos los valores más pequeños que nuestro elemento
    for(int* nextElement = cycleStart + 1; nextElement < data + size; nextElement++) {
      if(*nextElement < element)
        pointer++;
    }

    // Si el elemento ya está en la posición correcta
    if(pointer - data == cycleStart - data) {
      std::cout << "\nciclo: " << (cycleStart - data) << " -> item = "<< *pointer << " ya está en su posición";
      continue;
    }

    // Ignorar elementos duplicados
    while(element == *pointer)
      pointer++;

    // Poner el valor en la posición correcta
    if (pointer - data != cycleStart - data) {
      std::cout << "\nciclo: " << (cycleStart - data) << " -> item = "<< *pointer << " ";
      int tmp = *pointer;
      *pointer = element;
      element = tmp;
      std::cout << *pointer;
    }

    // Ciclo para el resto de elementos
    while(pointer - data != cycleStart - data) {
      pointer = cycleStart;

      // Encuentra la posición donde ponemos el elemento
      for(int* nextElement = cycleStart + 1; nextElement < data + size; nextElement++)
        if(*nextElement < element)
          pointer++;

      // Ignorar elementos duplicados
      while(element == *pointer)
        pointer++;

      // Poner el valor en la posición correcta
      if (element != *pointer) {
        std::cout << "\nciclo: " << (cycleStart - data) << " -> item = "<< *pointer << " ";
        int tmp = *pointer;
        *pointer = element;
        element = tmp;
        std::cout << *pointer;
      }
    }
  }

  std::cout << "\n\nDespués de ordenar: " << std::endl;
  for(int* e = data; e < data + size; e++) 
    std::cout << *e << " ";

  return 0;
}