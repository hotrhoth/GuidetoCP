#include <bits/stdc++.h>
#include <iostream>
#include <limits.h>
using namespace std;

const int MOD = 1e9 + 7;
const int maxn = 1000005;
long long c[maxn], dp[maxn];

int main() {
    long long n, x;
    cin >> n >> x;

    for(int i=0; i<n; i++) cin >> c[i];
    sort(c, c+n);

    dp[0] = 1;
    for(int j=0; j<n; j++) {
        for(int i=1; i<=maxn; i++) {
            if(i-c[j]>=0) dp[i] = (dp[i] + dp[i-c[j]]) % MOD;
        }
    }
    cout << dp[x] % MOD;
}