#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int dp[505][505];
const int inf = INT_MAX;

int main() {
    int a, b; cin >> a >> b;
    if(a>b) swap(a,b);
    for(int i=0; i<=b+1; i++) {
        dp[i][i] = 0;
    }
    for(int i=1; i<=b+1; i++) {
        for(int j=i+1; j<=b+1; j++) {
            dp[i][j] = inf;
            for(int k=1; k<=j; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
            for(int k=1; k<=i; k++) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
            dp[j][i] = dp[i][j];
        }
    }
    cout << dp[a][b];
}