#include <iostream>
#include <time.h>

int main() {
  srand(time(0));

  const int I_height = 5;
  const int I_width = 5;

  int I[I_height][I_width];
  // = {
  //   {4,2,1,0,0},
  //   {2,1,5,0,0},
  //   {1,2,1,4,0},
  //   {2,3,1,1,1},
  //   {1,1,0,0,0}
  // };

  // Random matrix

  std::cout << "I:" << std::endl;
  for (int* p = *I; p < *I + (I_width * I_height); p++) {
    *p = rand() & 10;
    std::cout << *p <<"  ";
  }

  int KA[] = {1, 2, 1};
  int KA_len = sizeof(KA)/sizeof(*KA);

  int KL[] = {-1, 0, 1};
  int KL_len = sizeof(KL)/sizeof(*KL);

  int OP[KA_len][I_width];
  int* OP_c = *OP;

  int O[KL_len][KL_len];
  int* O_c = *O;

  // I x KA = OP

  int ith = 0;
  int itv = 0;

  for (int* p = *I; p < *I + (I_width * I_height); p++) {

    int total = 0;
    for (int* e = KA; e < KA + KA_len; e++) {
      int idx = (e - KA);
      int base = *(*(I + (itv + idx)) + ith);
      total += base * (*e);
    }

    *OP_c = total;
    OP_c++;
  
    ith++;

    if (ith == I_width) {
      ith = 0;
      itv++;
    }

    if (itv > I_height - KA_len)
      break;
  }

  // console output

  std::cout << "\nOP:" << std::endl;
  for (int* p = *OP; p < *OP + (I_width * KA_len); p++)
    std::cout << *p <<"  ";

  // OP x KL = O

  ith = 0;
  itv = 0;

  for (int* p = *OP; p < *OP + (I_width * KA_len); p++) {

    int total = 0;
    for (int* e = KL; e < KL + KL_len; e++) {
      int idx = (e - KL);
      int base = *(*(OP + ith) + (itv + idx));
      total += base * (*e);
    }

    *O_c = total;
    O_c++;

    itv++;

    if (itv == KL_len) {
      itv = 0;
      ith++;
    }

    if (ith > I_width - KL_len) 
      break;
  }

  // console output

  std::cout << "\nO:" << std::endl;
  for (int* p = *O; p < *O + (KL_len * KL_len); p++)
    std::cout << *p <<"  ";

  return 0;
}
