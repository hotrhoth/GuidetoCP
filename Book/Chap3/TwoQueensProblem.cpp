#pragma GCC target ("arch=sandybridge")
#include <iostream>
using namespace std;

int main() {
    double res; 
    for(int n=0; n<20; n++) {
        res = 1.0/2 * n * n * n * n - 5.0/3 * n * n * n + 3.0/2 * n * n - 1.0/3 * n;
        if(res < 1e-9) {
            cout << "0\n";
            continue;
        }
        cout << 1LL * res << "\n";
    }
    
}