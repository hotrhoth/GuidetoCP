#include <iostream>
#include <queue>
using namespace std;

#define f(i,a,b) for(int i=a; i<b; i++)
typedef pair<int, int> pii;
#define x first
#define y second

int n, m, sx, sy, ex, ey;
bool vis[1002][1002];
char c, ans[10000004], par[1002][1002];
int dis[1002][1002];

int h[] = {1, -1, 0, 0}, v[] = {0, 0, 1, -1};
queue <pii> q;

bool isvalid(int dx, int dy) {
    return (0<=dx && dx<n && 0<=dy && dy<m);
}

string stepDir = "DURL";

// bfs tai vi tri bat dau toi het
int main() {
    cin >> n >> m;
    f(i,0,n) {
        f(j,0,m) {
            cin >> c;
            if(c=='#') vis[i][j] = true;
            else if(c=='A') {sx=i; sy=j;}
            else if(c=='B') {ex=i; ey=j;}
        }
    }

    vis[sx][sy] = true;
    q.push({sx,sy});
    while(!q.empty()) {
        pii p = q.front(); q.pop();
        f(i,0,4) {
            int dx = p.x + h[i], dy = p.y + v[i];
            if(isvalid(dx,dy) && !vis[dx][dy]) {
                par[dx][dy] = stepDir[i];
                dis[dx][dy] = dis[p.x][p.y]+1;
                vis[dx][dy] = true;
                q.push({dx,dy});
            }
        }
    }

    if(!vis[ex][ey]) {cout << "NO\n"; return 0;}

    cout << "YES\n" << dis[ex][ey] << "\n";
    pii p = {ex, ey};
    for(int i=dis[ex][ey]; i>0; i--) {
        ans[i] = par[p.x][p.y];
        if(ans[i] == 'D')       p = {p.x-1, p.y};
        else if(ans[i] == 'U')  p = {p.x+1, p.y};
        else if(ans[i] == 'R')  p = {p.x, p.y-1};
        else if(ans[i] == 'L')  p = {p.x, p.y+1};
    }
    
    for (int i = 1; i <= dis[ex][ey]; i++){
       cout << ans[i];
    }
    
}