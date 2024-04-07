#include <iostream>
#include <queue>

using namespace std;

const int N = 1000;

// vector <pair<int, int>> adj[N];
// int adj[N][N];
// vector <tuple<int, int, int>> edges;

vector <int> adj[N];
bool visited[N];

// O(n + m)
void dfs(int s) {
    if(visited[s]) return;
    visited[s] = true;

    for(auto u: adj[s]) {
        dfs(u);
    }
}

queue <int> q;
int dis[N];

void bfs(int x) {
    visited[x] = true;
    dis[x] = 0;
    q.push(x);
    while(!q.empty()) {
        int s = q.front(); q.pop();

        for(auto u: adj[s]) {
            if(visited[u]) continue;
            visited[u] = true;
            dis[u] = dis[s] + 1;
            q.push(u);
        } 
    }
}