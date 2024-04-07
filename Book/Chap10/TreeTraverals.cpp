#include <iostream>
using namespace std;

#define N 100
vector <int> adj[N];
int cnt[N]; // so node trong subtree cua no

void dfs(int s, int e) {
    cnt[s] = 1;
    for(auto u: adj[s]) {
        if(u==e) continue;
        dfs(u, s);
        cnt[s] += cnt[u];
    }
}