#include <iostream>
#include <time.h>

int main(){
  srand(time(0));

  const int I_x = 7;
  const int I_y = 7;
  const int I_z = 3;

  const int K_x = 3;
  const int K_y = 3;
  const int K_z = 3;

  const int R_x = (I_x - K_x) + 1;
  const int R_y = (I_y - K_y) + 1;
  const int R_z = 3;

  int I[I_z][I_y][I_x];
  int K[K_z][K_y][K_x];
  int R[R_z][R_y][R_x];

  int idx = 0;

  // Generacion de datos para I de 1 a 5
  for (int* p = **I; p < **I + (I_x * I_y * I_z); p++) {
    *p = rand() & 5;
    std::cout << *p <<"  ";

    idx++;

    if (idx == I_x) {
      std::cout << std::endl;
      idx = 0;
    }
  }

  std::cout << std::endl;

  // Generacion de datos para K de 1 a 5
  idx = 0;
  for (int* p = **K; p < **K + (K_x * K_y * K_z); p++) {
    *p = rand() & 5;
    std::cout << *p <<"  ";

    idx++;

    if (idx == K_x) {
      std::cout << std::endl;
      idx = 0;
    }
  }

  std::cout << std::endl;

  // Calculo de datos para R
  int* I_p;
  int I_next_h;
  int I_idx = 0;

  int* K_p = **K;
  int K_2Dlen = K_x * K_y;
  int K_next = K_2Dlen;

  int R_2Dlen = R_x * R_y;
  int R_short_next = R_x;
  int R_next = R_2Dlen;

  // Se recorre el array de dimensiones de forma completa 1 a 1
  for (int* p = **R; p < **R + R_2Dlen * R_z; p++) {

    // Se verifica la posicion de I para realizar el salto a la siguente linea o matrix dimensional
    if (p - **R == R_short_next) {
      I_idx += K_x - 1;
      R_short_next += R_x;
    }
    I_p = **I + I_idx;
    I_next_h = K_x;

    // Se recorre los grupos de K reflejado en I para realizar el calculo
    int total = 0;
    for (int* q = K_p; q < **K + K_next; q++) {
      // Se refleja el movimiento de 3 a 3 en una matrix de 7x7 calculado en 5 movimientos.
      if(q - **K == I_next_h) {
        I_p = I_p + R_x - 1;
        I_next_h += K_x;
      }

      // Se realiza la Multiplicacion de I * K, para acumular y luego agregarar la suma total a R
      total += (*q) * (*I_p);
      I_p++;
    }
    // El resultado calculado se agrega a R que es el resultado
    *p = total;
    I_idx++;

    // Se calcula la dimension actual en la que se encuentra de 1 a 3
    if (p - **R == R_next) {
      K_p = **K + K_next;
      K_next += K_2Dlen;
      R_next += R_2Dlen;
      I_idx = I_x * I_y;
      R_short_next = R_x;
    }
  }

  // Resultado de R
  idx = 0;
  for (int* p = **R; p < **R + R_2Dlen * R_z; p++) {
    std::cout << *p <<"  ";

    idx++;

    if (idx == R_x) {
      std::cout << std::endl;
      idx = 0;
    }
  }

  return 0;
}