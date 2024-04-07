#include <bits/stdc++.h>
#include <iostream>
#include <limits.h>
using namespace std;

const int maxn = 1000005;
long long c[maxn], dp[maxn];

int main() {
    long long n, x;
    cin >> n >> x;

    for(int i=0; i<n; i++) cin >> c[i];
    sort(c, c+n);
    
    for(int i=1; i<=maxn; i++) {
        dp[i] = INT_MAX;
        for(int j=0; j<n; j++) {
            if(i-c[j]>=0) dp[i] = min(dp[i], dp[i-c[j]]+1);
        }
    }
    if(dp[x]!=INT_MAX) cout << dp[x];
    else cout << -1;
}