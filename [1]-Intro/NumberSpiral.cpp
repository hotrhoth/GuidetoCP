#include <iostream>
using namespace std;

int main() {
    // row y col x
    long long q, r, c;
    cin >> q;
    while(q--) {
        cin >> r >> c; 

        long long t = max(r, c);
        if(r == c) {
            cout << t * t - (t-1);
        }
        else if(r > c) {
            if(r&1) cout << (t * t - (t-1) - (r-c));
            else cout << (t * t - (t-1) + (r-c));

        }
        else {
            if(c&1) cout << (t * t - (t-1) + (c-r));
            else cout << (t * t - (t-1) - (c-r));
        }
        cout << "\n";
    }
}