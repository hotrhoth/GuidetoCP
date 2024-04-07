#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9+7;

int main() {
    int n; cin >> n;
    int target = n*(n+1)/2;
    if(target&1) {
        cout << 0; return 0;
    } 
    long long ret = 0; target/=2;
    
    // dp[i][x]
    
    vector <vector<long long>> dp(n, vector<long long> (target+1, 0));
    dp[0][0] = 1;
    for(int i=1; i<n; i++) {
        for(int t=0; t<=target; t++) {
            dp[i][t] = dp[i-1][t];
            int left = t-i;
            if(left>=0) (dp[i][t] += dp[i-1][left])%=mod;
        }
    }

    cout << dp[n-1][target];
}