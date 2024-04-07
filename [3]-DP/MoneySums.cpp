#include <iostream>
#include <vector>
using namespace std;

int coins[105];
bool dp[105][100005];

int main() {
    int n, lm = 0, ans = 0; cin >> n;
    dp[0][0] = true;

    for(int i=0; i<n; i++) {
        cin >> coins[i];
        lm += coins[i];
    } 
    for(int i=1; i<=n; i++) {
        for(int cur = 0; cur <= 100005; cur++) {
            dp[i][cur] = dp[i-1][cur];
            int pre = cur - coins[i-1];
            if(pre >=0 && dp[i-1][pre]) {
                dp[i][cur] = true;
            }
        }
    }
    
    vector <int> possible;
    for(int sum=1; sum<=lm; sum++) {
        if(dp[n][sum]) {
            ans ++;
            possible.push_back(sum);
        } 
    }
    cout << ans << "\n";
    for(auto sum:possible) cout << sum << " ";
    
}