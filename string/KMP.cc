#include <iostream>
using namespace std;

void setNext(char* t, int len, int* next) {
    int iSuf,iPre;
    iSuf = 0; 
    iPre = -1;
    next[0] = -1;

    while (iSuf < len) {
        if (iPre == -1 || *(t+iPre) == *(t+iSuf)) {
            iSuf++;
            iPre++;
            *(next+iSuf) = iPre;
        } else
            iPre = *(next+iPre);
    }
}

int index(char* sMain, int lenMain, char* sSub, int lenSub, int* next, int pos) {
    int iMain = pos;
    int iSub = 0;
    while (iMain < lenMain && iSub < lenSub) {
        if (iSub == -1 || *(sMain+iMain) == *(sSub+iSub)) {
            iMain++;
            iSub++;
        }
        else
            iSub = next[iSub];
    }

    if (iSub == lenSub)
        return iMain - lenSub;
    else 
        return -1;
}
int main() {
    char subString[9] = "abaaabab";
    char mainString[21] = "abssabaacdabaacdabad";
    int next[8];
    setNext(subString, 8, next);
    for (int i = 0; i < 8; i++) {
        cout<<next[i]<<endl;
    }
    cout<<index(mainString, 20, subString, 8, next, 0)<<endl;
    
    return 1;
}
