#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define t 5
void Binaryofx(int x) {
    for(int k=31; k>=0; k--) {
        if(x&(1<<k)) cout << "1";
        else cout << "0";
    }
    cout << "\n";
}

int main() {
    int x = 14;
    cout << "x: "; Binaryofx(x);
    cout << "t: "; Binaryofx(1<<t);

    x = (x | (1<<t)); // set tth bit to 1
    cout << "x: "; Binaryofx(x);
    x = (x & ~ (1<<t)); // set tth bit to 0
    cout << "x: "; Binaryofx(x);

    x = (x ^ (1<<t)); // invert kth bit
    cout << "x: "; Binaryofx(x);

    x = (x & (x-1)); // set last bit to 0
    cout << "x: "; Binaryofx(x);
    x = (x & -x); // set all 1 to 0, except the last one
    cout << "x: "; Binaryofx(x);

    x = (x | (x-1)); // invert all bit after the last one
    cout << "x: "; Binaryofx(x);
    cout << x << " is ";
    if ((x & (x-1))==0) // invert all bit after the last one
        cout << "power of two\n";
    else cout << "not power of two\n";

    int b = 0;
    do {
        Binaryofx(b);
        b = (b-x)&x;
    } while(b);
}