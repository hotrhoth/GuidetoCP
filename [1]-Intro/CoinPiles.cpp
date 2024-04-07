#include <iostream>
using namespace std;

int main() {
    long long t, a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        /*
        2m + n = a
        2p + q = b
        m + n = p + q
        m = q, n = p
        2m + n = a
        2n + m = b
        -> 2 * a - b = 3 * m
        -> 2 * b - a = 3 * n
        */
        if ((a+b)%3==0 &&(2*a>=b) && (2*b>=a) 
        &&(2*b-a)/3 + (2*a-b)/3 == (a+b)/3)
            cout << "YES";
        else cout << "NO";
       cout << "\n";
    }
}