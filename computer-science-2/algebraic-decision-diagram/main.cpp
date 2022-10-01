#include <iostream>

void print(int* datasource, int length) {
    for(int* ptr = datasource; ptr < datasource + length; ptr++)
        std::cout << *ptr;

    std::cout << std::endl;
}

int f(int*  x1, int* x2) {
    int ADD[] = {101, 102, 2, 10, 0};
    int length = sizeof(ADD) / sizeof(*ADD);

    int* ptr = ADD;

    // FIX ME 
    if (*x1)
        ptr++;
    else
        ptr += 2;

    if (*x2)
        ptr++;
    else
        ptr += 2;
    // END

    return *ptr;
}

int g(int*  x1, int* x2) {
    int ADD[] = {101, 2, 8, 10, 11};
    int length = sizeof(ADD) / sizeof(*ADD);

    int* ptr = ADD;

    // FIX ME 
    if (*x1)
        ptr++;
    else
        ptr += 2;

    if (*x2)
        ptr++;
    else
        ptr += 2;
    // END

    return *ptr;
}

int main() {
    int datasource[][2] = {{1, 1}, {1, 0}, {0, 1}, {0, 0}};
    int length = sizeof(datasource) / sizeof(*datasource);

    for (int (*ptr)[2] = datasource; ptr < datasource + length; ptr++)
    {
        int* x = *ptr;

        int fResult = f(x, x + 1);
        int gResult = g(x, x + 1);

        std::cout << "f(" << *x << "," << *(x + 1) << ")=" << fResult << std::endl;
        std::cout << "g(" << *x << "," << *(x + 1) << ")=" << gResult << std::endl;
    
        std::cout << "f + g =" << fResult + gResult << std::endl;
        std::cout << "--------------------------" << std::endl;
    }
    

    return 0;
}