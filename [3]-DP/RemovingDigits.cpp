#include <iostream>
#include <climits>
using namespace std;

const int maxn = 1e6;
long long n, dp[maxn+1];

int main() {
    cin >> n;
    fill(dp+1, dp+n+1, INT_MAX);
    for(int i=1; i<=n; i++) {
        int d = i;
        while(d>0) {
            if(d%10 != 0) dp[i] = min(dp[i], dp[i-(d%10)]+1);
            d /= 10;
        }
    }

    cout << dp[n];
}