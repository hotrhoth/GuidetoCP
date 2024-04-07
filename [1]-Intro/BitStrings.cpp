#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    long long mod = 1e9+7;
    long long x = pow(2, 50);
    x = x % mod;
    long long ret = 1;

    if(n>50) {
        int t = n / 50;
        int r = n - t * 50;
        for(int i=1; i<=t; i++) {
            ret *= x;
            ret %= mod;
        }
        long long tmp = pow(2, r);
        tmp %= mod;
        ret = (ret * tmp) % mod;
    }
    else{
        ret = pow(2, n);
        ret = ret % mod;
    }

    cout << ret;
}