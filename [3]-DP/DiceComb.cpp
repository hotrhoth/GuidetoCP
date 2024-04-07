#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
long long dp[1000001];

int main() {
    long long n; cin >> n;
    long long ret = 0;
    dp[0] = 1; dp[1] = 1; 
    // 2, 2 11
    for(int i=2; i<1000001; i++) {
        int x = 1;
        while(i>=x && x<=6) {
            dp[i] = (dp[i] + dp[i-x]) % MOD;
            x++;
        }
    }
    cout << dp[n] % MOD;
    
}