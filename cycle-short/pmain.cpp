#include <iostream>
#include <string>

int main()
{
  int data[] = {9, 7, 8, 3, 4};
  
  int wr,  
      size = sizeof(data)/sizeof(*data);
  int* len = (data + size);

  for (int* c = (data + 0); c < len; c++)
  {
    // int p = (c - data);
    // const int cp = p;
    int* t = c;

    int ct = 0;
    for (int* d = c + 1; d < len; d++) {
      if (*c > *d) {
        t++;
        ct++;
      }
    }

    std::cout << *c << "   " << ct<< "   "<< *t << std::endl;

    // if (cp == p) continue;
    //
    // while(c == c + p) p++;

    // int* tmp = c;
    // tmp = tmp + p;
    //   
    // std::swap(3, c); 
  
/*     std::cout << std::endl << *c << "*"<< p <<"*"<< *(c + p)<< std::endl; */

    // wr++;
    //
    //     std::cout << std::endl <<"+++++++++" << std::endl;
    //
    //   for (int* z = data; z < len; z++)
    //   {
    //     std::cout << *z << "-";
    //   }
    //
    //   std::cout << std::endl <<"-----------" << std::endl;

    // while(cp != p)
    // {
    //   p = cp;
    //   for(int* e = c + 1; e < len; e++)
    //     if(*c > *e) p++;
    //
    //   while(c == c + p) p++;
    //
    //   tmp = c;
    //   tmp = tmp + p;
    //       
    //   std::cout << *c << "/a/" << *tmp << std::endl;
    //
    //   std::swap(*c, *tmp);
    //
    //   std::cout << *c << "/b/" << *tmp << std::endl;
    //  
    //   wr++;
    // }
    //
    //
    // std::cout << p << std::endl;
    // std::cout << "-------" << std::endl;

  }

  // if () {
  //   continue;
  // }
  //
  return 0;
}
