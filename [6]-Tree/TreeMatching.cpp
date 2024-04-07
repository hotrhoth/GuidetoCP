#include <iostream>
#include <vector>
using namespace std;

#define f(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
const int maxn = 2e5 + 2;

vector <int> adj[maxn];
int dp[maxn][2];

void dfs(int v, int p) {
    // take no edges
    for(int to: adj[v]) {
        if(to!=p) {
            dfs(to,v);
            dp[v][0] += max(dp[to][0], dp[to][1]);
        }
    }

    // take 1 edges
    for(int to: adj[v]) {
        if(to!=p) {
            dp[v][1] = max(dp[v][1], dp[to][0] + 1 + dp[v][0] - max(dp[to][0], dp[to][1]));
        }
    }
}

int main() {
    int n; cin >> n;
    f(i,0,n-1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0,-1);
    cout << max(dp[0][0], dp[0][1]);
}