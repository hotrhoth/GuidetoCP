#include <iostream>
using namespace std;;

// upper-left to lower-right
long long dp[1002][1002];
const int mod = 1e9 + 7;

// right and down
int main() {
    int n; string s;
    cin >> n;
    dp[0][0] = 1;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<n; j++) {
            if(s[j]!='*') {
                if(i>0){
                    dp[i][j] += dp[i-1][j];
                    dp[i][j] %= mod;
                }
                if(j>0){
                    dp[i][j] += dp[i][j-1];
                    dp[i][j] %= mod;
                }
            } 
            else dp[i][j] = 0;
        }
    }
    cout << dp[n-1][n-1];
}