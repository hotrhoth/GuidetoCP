#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e5+1;
const int maxm = 101;
const int mod = 1e9 + 7;

long long n, m, dp[maxn][maxm];

int main() {
    cin >> n >> m;
    vector <long long> values(n);
    for(int i=0; i<n; i++) cin >> values[i];

    if(values[0]!=0) dp[0][values[0]] = 1;
    else for(int i=1; i<=m; i++) dp[0][i] = 1;

    for(int i=1; i<n; i++) {
        if(values[i]==0) {
            for(int j=1; j<=m; j++) {
                if(j-1>=1) dp[i][j] = (dp[i][j] + dp[i-1][j-1])%mod;
                dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
                if(j+1<=m) dp[i][j] = (dp[i][j] + dp[i-1][j+1])%mod;
            }
        }
        else {
            if(values[i]-1>=1) dp[i][values[i]] = (dp[i][values[i]] + dp[i-1][values[i]-1])%mod;
            dp[i][values[i]] = (dp[i][values[i]] + dp[i-1][values[i]])%mod;
            if(values[i]+1<=m) dp[i][values[i]] = (dp[i][values[i]] + dp[i-1][values[i]+1])%mod;
        }
    }
    long long ret = 0;
    for(int i=1; i<=m; i++) ret = (ret + dp[n-1][i])%mod;
    ret %= mod;
    cout << ret;
}