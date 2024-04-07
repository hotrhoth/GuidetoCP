#include <iostream>
using namespace std;

void Binaryofx(int x) {
    for(int k=31; k>=0; k--) {
        if(x&(1<<k)) cout << "1";
        else cout << "0";
    }
    cout << "\n";
}

int hamming(int a, int b) {
    return __builtin_popcount(a^b);
}

int main() {
    string a = "00111", b="01101";;
    // h chuyen qua int la duyet ngc
}