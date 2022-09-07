#include <iostream>
#include <time.h>
#include <cstdio>

int *generate(int length)
{
    int *data = new int[length];

    srand(time(0));

    for (int *ptr = data; ptr < data + length; ptr++)
        *ptr = rand() & 100;

    return data;
}

void print(int *data, int length, char const *title = "")
{
    printf("- %s -\n", title);

    for (int *ptr = data; ptr < data + length; ptr++)
        std::cout << *ptr << std::endl;
}