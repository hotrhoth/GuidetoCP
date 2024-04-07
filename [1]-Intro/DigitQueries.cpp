#include <iostream>
using namespace std;

// faster pow
long long xpow(long long x, long long y) {
    long long ret = 1;
    while(y>0) {
        if(y&1) ret *= x;
        y >>=1; x = x*x;
    }
    return ret;
} 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {

        long long n; cin >> n;
        long long c = 1;
        for(long long p=9;; n-=p, c++, p = 9*xpow(10, c-1) * c) {
            if(n-p <= 0) break;
        }

        // n<=p, c la so chu so cua so ans
        n--;
        // x la so do, y la vi tri cua chu so
        long long x = n/c, y= n%c;
        long long ans = xpow(10, c-1) + x;
        string s = to_string(ans);
        cout << s[y] << "\n";
    }
}