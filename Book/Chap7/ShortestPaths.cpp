#include <iostream>
#include <queue>

using namespace std;

const int inf = 1e6;
const int N = 10000;

int n, m;
vector <tuple<int, int, int>> edges;
int dis[N];

void BellmanFord(int x) {
    for(int i=1; i<=n; i++)
        dis[i] = inf;
    dis[x] = 0;

    // contain at most n-1 edges
    for(int i=1; i<=n-1; i++) {
        for(auto e: edges) {
            int a, b, w;
            tie(a, b, w) = e;
            dis[b] = min(dis[b], dis[a] + w);
        }
    }
    // chay them lan nx ma tim dc nho hon thi detect negative cycle
}

vector <pair<int,int>> vadj[N];
priority_queue <pair<int, int>> q;
// (-d, x)
bool processed[N];

void Dijkstra(int x) {
    for(int i=1; i<=n; i++)
        dis[N] = inf;
    
    dis[x] = 0;
    q.push({0, x});
    while(!q.empty()) {
        int a = q.top().second; q.pop();
        if(processed[a]) continue;

        processed[a] = true;
        for(auto u: vadj[a]) {
            int b = u.first, w = u.second;
            if(dis[a] + w < dis[b]) {
                dis[b] = dis[a] + w;
                q.push({-dis[b], b});
            }
        }
    }
}

int adj[N][N];
int dist[N][N];

void FloydWarshall() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=1; j++) {
            if(i==j) dist[i][j] = 0;
            else if(adj[i][j]) dist[i][j] = adj[i][j];
            else dist[i][j] = inf;
        }
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=1; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
