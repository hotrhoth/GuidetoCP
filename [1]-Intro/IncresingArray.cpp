#include <iostream>
using namespace std;

int main() {
    long long n, x1, x2, ret = 0;
    cin >> n; 
    cin >> x1;
    for(int i=1; i<n; i++) {
        cin >> x2;
        // cout << x1 << " " << x2 << "\n";
        if(x2<x1) {
            ret += (x1-x2);
            // cout << ret << "\n";
            x2 = x1;
        }
        x1 = x2;

    }
    cout << ret;
}