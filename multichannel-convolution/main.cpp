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

  for (int* p = **I; p < **I + (I_x * I_y * I_z); p++) {
    *p = rand() & 5;
    std::cout << *p <<"  ";

    idx++;

    if (idx == I_x) {
      std::cout << std::endl;
      idx = 0;
    }
  }

  for (int* p = **K; p < **K + (K_x * K_y * K_z); p++) {
    *p = rand() & 5;
  }

  int* I_p;
  int I_next_h;
  int I_idx = 0;

  int* K_p = **K;
  int K_2Dlen = K_x * K_y;
  int K_next = K_2Dlen;

  int R_2Dlen = R_x * R_y;
  int R_short_next = R_x;
  int R_next = R_2Dlen;

  for (int* p = **R; p < **R + R_2Dlen * R_z; p++) {

    if (p - **R == R_short_next) {
      I_idx += K_x - 1;
      R_short_next += R_x;
    }
    // std::cout << "-***-"<< I_idx <<"-----\n";
    I_p = **I + I_idx;
    I_next_h = K_x;

    for (int* q = K_p; q < **K + K_next; q++) {
      if(q - **K == I_next_h) {
        I_p = I_p + R_x - 1;
        I_next_h += K_x;
      }
      std::cout << *I_p <<"  ";
      I_p++;
    }

    I_idx++;

    std::cout << std::endl;

    if (p - **R == R_next) {
      K_p = **K + K_next;
      K_next += K_2Dlen;
      R_next += R_2Dlen;
      // I_idx = I_x * I_y;
      R_short_next = R_x;
      std::cout << "-----"<< I_idx <<"-----\n";
    }
  }

  return 0;
}