#include <iostream>

int main() {
  int const length = 8;
  int const size = length * length;
  int const QUEEN = 1;
  int const ONE = 1;

  // Caso de prueba 1
  
  int data[length][length] = {
      {0, 0, QUEEN, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, QUEEN, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, QUEEN},
      {0, QUEEN, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, QUEEN, 0, 0, 0, 0},
      {QUEEN, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, QUEEN, 0},
      {0, 0, 0, 0, QUEEN, 0, 0, 0}
  };

  // Caso de prueba 2

  // int data[length][length] = {
  //     {0, 0, QUEEN, 0, 0, 0, 0, 0},
  //     {0, 0, 0, 0, 0, QUEEN, 0, 0},
  //     {0, 0, 0, QUEEN, 0, 0, 0, QUEEN},
  //     {0, QUEEN, 0, 0, 0, 0, 0, 0},
  //     {0, 0, 0, QUEEN, 0, 0, 0, 0},
  //     {QUEEN, 0, 0, 0, 0, 0, 0, 0},
  //     {0, 0, 0, 0, 0, 0, QUEEN, 0},
  //     {0, 0, 0, 0, QUEEN, 0, 0, 0}
  // };

  bool found = false;

  // Se recorre el array desde la posicon 0 hasta la 63
  for (int *ptr = *data; ptr < *data + size; ptr++) {
   // Se evalua si el puntero esta en posicion de la reina
    if (*ptr == QUEEN) {
      // Se obtiene el indice
      int idx = ptr - *data;

      // Se obtiene posicion X y Y del array 2D, antes de la reina
      // <--length(x)-- QUEEN
      //
      //   ^
      //   |
      // length(y)
      //   |
      // QUEEN
      int x = idx % length;     
      int y = idx / length;

      x++;
      y++;

      // Se obtiene tamanio de espacios sobrantes despues de la reina
      // QUEEN --length-->
      int yr = (x + ONE - length);
      int x2 = x < y ? x : y;
      int y2 = y2 < yr ? y2 : yr; 

      int* checker = *data;
      
      // variables que evaluaran las paredes: 
      // horizontal-izquierdo(nx), vertical-superior(ny), lateral-izquierdo(nx2), lateral-derecho(ny2) 
      int n = ONE;
      int nx = ONE; 
      int ny = ONE; 
      int nx2 = ONE; 
      int ny2 = ONE;
      
      do {
        // Verifica posiciones haca atras antes de la reina: 
        // -1 (horizontal-izquierdo), -7 (lateral-derecho), -8 (vertical-superior), -9 (lateral-izquierdo)
        if(n < x) found = (checker = ptr - 1 * n, *checker == QUEEN);
        if(n < y2 && !found) found = (checker = ptr - 7 * n, *checker == QUEEN);
        if(n < y && !found) found = (checker = ptr - 8 * n, *checker == QUEEN);
        if(n < x2 && !found) found = (checker = ptr - 9 * n, *checker == QUEEN);
     
        // En caso de encontrar un error, termina el while.
        if(found) break;
      } while(++n, n < length); 

      if(found) {
        std::cout << "No es solucion" << std::endl;
        break;
      }
    }
  }
  
  if(!found)
    std::cout << "Solucion" << std::endl;
}
