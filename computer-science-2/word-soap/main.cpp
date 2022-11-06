#include <iostream>
#include <fstream>

using namespace std;

const int LENGHT = 12;
const int OUTPUT = 2;

bool compare(const char* data, const char* target) {
    while(*data != '\0' && *data == *target){
        target++;
        data++;
    }
    return *data == '\0';
}

void copy(char* data, char* target) {
    while(*data != '\0'){
        *target = *data;

        target++;
        data++;
    }
}

void load(char** data, char* target) {
    const char* empty = "";
    char line[LENGHT] = "";

    ifstream file("soap.txt");

    while(file >> line) {
        if (compare(empty, target)) {
            copy(line, target);
            continue;
        }

        *data = new char[LENGHT];
        copy(line, *data);
        data++;
    }
}

void unload(char** data) {
    for (char** i = data; i < data + LENGHT; i++)
    {
        delete[] *i;
    }
    delete[] data;
}

// bool moveTop(char** data, char* letter) {}
// bool moveTopRight(char** data, char* letter) {}
// bool moveRight(char** data, char* letter) {}
// bool moveRightBottom(char** data, char* letter) {}
// bool moveBottom(char** data, char* letter) {}
// bool moveBottomLeft(char** data, char* letter) {}
// bool moveLeft(char** data, char* letter) {}
// bool moveLeftTop(char** data, char* letter) {}

bool scan(char** data,  char* target) {
    return true;
}

void find(char** data) {
    int lptr = -1;
    int rptr = -1;
    bool isFind = false;

    for (char** j = data; j < data + LENGHT; j++)
    {   int y = (j - data) + 1;

        for(char* k = *j; k < *j + LENGHT; k++) 
        {
            int x = (k - *j) + 1;
            isFind = scan(data, k);
            if (isFind) {
                lptr = x;
                rptr = y;
                break;
            }
        }
        
        if(isFind) break;
    }
    
    cout << "(" << lptr << "," << rptr << ")";
}

int main() {
    char** data = new char*[LENGHT];
    char target[LENGHT] = "";

    load(data, target);
    find(data); 
    unload(data);

    return 0;
}