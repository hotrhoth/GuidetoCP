#include <iostream>
using namespace std;

const int mod = 1e9 + 7;
const int maxN = 1e6 + 6;

long long dp[maxN][3];

// n * 2
// 1->n * 1, 1->n * 2
int main() {
    int t; cin >> t;
    int n;

    //                                      _  _
    // dp[i][1] = last blocks are separate | || |
    //                                   _ _
    // dp[i][2] = last blocks are fused |   |
    // transition:
    /*
        - -      _ _     _ _     _ _     _ _     _ _
       | | | => | | |,  |_| |,  | |_|,  |_|_|,  |_ _|
                | | |   | | |   | | |   | | |   | | |

                     _ _    _ _    _ _ 
         _ _        |   |  |_|_|  |_ _|
        |   |  =>   |   |, |   |, |   |
    */
    dp[1][1] = dp[1][2] = 1;
    for(int i=2; i<=maxN; i++) {
        dp[i][1] = (dp[i-1][1]*4 + dp[i-1][2])%mod;
        dp[i][2] = (dp[i-1][1] + dp[i-1][2]*2)%mod;
    }
    while(t--) {
        cin >> n;
        cout << (dp[n][1] + dp[n][2])%mod << "\n";
    }
}