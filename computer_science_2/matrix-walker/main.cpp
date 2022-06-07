#include <iostream>
#include <stdio.h>

// Definicion de tipos de funciones
typedef void MoveFunc(int*, int*);
typedef void ActionFunc(int**, int*, int*);

// Funcion encargada de generar un array dinamico,
// Para iniciar requiere el ancho y alto del array 
int** genMatrix(int width, int height) {
  int** m = new int*[height];

  int counter = 0;

  for (int** p = m; p < m + height; p++) {
    *p = new int[width];
    for (int* q = *p; q < *p + width; q++) {
      counter++;
      *q = counter;
    }
  }

  return m;
}

// Funcion encargada de realizar el movimiento vertical
void vertical(int* x, int* y) {
  *y += 1;
}

// Funcion encargada de realizar el movimiento horizontal
void horizontal(int* x, int* y) {
  *x += 1;
}

// Funcion encargada de realizar el incremento
void increase(int** base, int* x, int* y) {
  int** row = base + *y;
  int* col = *row + *x;
  int* ptr = col;

  int tmp = *ptr;
  *ptr += 1;
  
  printf("Posicion: {x:%i, y:%i}\tAumentar(%i): %i\n", *x, *y, tmp, *ptr); 
}

// funcion encargada de realizar el decremento
void decrease(int** base, int* x, int* y) {
  int** row = base + *y;
  int* col = *row + *x;
  int* ptr = col;

  int tmp = *ptr;
  *ptr -= 1;
  
  printf("Posicion: {x:%i, y:%i}\tDisminuir(%i): %i\n", *x, *y, tmp, *ptr); 
}

int main() {
  // Se define las variables a utilizar en toda la applicacion
  int width = 5;
  int height = 12;
  int actionSize = 13; // tamanio de acciones y movimientos
  int positionX = 0;
  int positionY = 0;

  // Se genera un array dinamico, y se prepara los movimientos y operaciones que se realizaran
  int** matrix = genMatrix(width, height);
  int* movement  = new int[actionSize] { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0 };
  int* operation = new int[actionSize] { 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 };

  // Se prepara el array de movimiento y acciones
  MoveFunc* funcMovements[] = { &vertical, &horizontal };
  ActionFunc* funcActions[] = { &increase, &decrease }; 

  // Se inicia la iteracion con base a los movimientos, seguido de las operaciones en su mismo nivel
  for (int* mov = movement; mov < movement + actionSize; mov++, operation++) {
    // Con la posicion del puntero, se obtiene el movimiento y accion actual
    MoveFunc** currentMovement = funcMovements + *mov;
    ActionFunc** currentAction = funcActions + *operation;
    
    // Se ejecuta la funcion actual de accion y movimiento que se realizar en ese punto
    (*currentAction)(matrix, &positionX, &positionY);
    (*currentMovement)(&positionX, &positionY);
  }
}
