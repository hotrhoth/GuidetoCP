#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int l = 5005;
int dp[l][l]; 
// ket qua cua dp khi toi i cua n va j cua m
/*

*/

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string n, m;
    cin >> n >> m;
    for(int i=0; i<=n.size(); i++) {
        for(int j=0; j<=m.size(); j++) {
            if(i==0) dp[i][j] = j;
            else if(j==0) dp[i][j] = i;
            else if(n[i-1]==m[j-1]) dp[i][j] = dp[i-1][j-1];
            else {
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
    }
    cout << dp[n.size()][m.size()];
}