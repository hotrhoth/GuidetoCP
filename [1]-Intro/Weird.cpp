#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    cout << n;
    while(n!=1) {
        cout << " ";
        if(n&1) {
            n = n*3+1;
        }
        else n = n >> 1;
        cout << n;
    }
}