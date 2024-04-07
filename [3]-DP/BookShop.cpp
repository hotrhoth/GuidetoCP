#include <iostream>
using namespace std;

int dp[1005][100005], h[1005], s[1005];

int main() {
    int n, x; cin >> n >> x;

    for(int i=0; i<n; i++) 
        cin >> h[i];
    for(int i=0; i<n; i++) 
        cin >> s[i];

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=x; j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= h[i-1])
                dp[i][j] = max(dp[i][j], dp[i-1][j-h[i-1]] + s[i-1]);
        }
    }
    cout << dp[n][x];
}