#include <iostream>
using namespace std;

int index(char* s, int lenS, char* t, int lenT, int pos) {
    int i = pos;

    int j = 0;

    while (i + lenT - 1 - j < lenS && j < lenT) {
        if (*(s+i) == *(t+j)) {
            i++;
            j++;
        }
        else {
            i = i - j + 1;
            j = 0;
        }
    }

    if (j == lenT)
        return (i - lenT);
    else 
        return -1;
}

int main() {
    char a[4] = {'a','b','c','d'};
    char b[10] = {12, 34,'c','a','b','c','d','a','d','f'};
    cout<<index(b, 10, a, 4, 0)<<endl;

    return 0;
}

