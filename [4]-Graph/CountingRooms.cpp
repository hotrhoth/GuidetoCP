#include <iostream>
using namespace std;

#define f(i,a,b) for(int i=a; i<b; i++)

char c;
int n, m, cnt;
int h[] = {1, -1, 0, 0}, v[] = {0, 0, 1, -1};
bool vis[1002][1002];

bool isvalid(int dx, int dy) {
    return (0<=dx && dx<n && 0<=dy && dy<m);
}

void dfs(int x, int y) {
    vis[x][y] = true;
    f(i,0,4){
        int dx = x+h[i], dy=y+v[i];
        if(isvalid(dx,dy) && !vis[dx][dy])
            dfs(dx,dy);
    }
}

int main() {
    cin >> n >> m;
    f(i,0,n) {
        f(j,0,m) {
            cin >> c;
            vis[i][j] = (c=='#');
        }
    }

    f(i,0,n) {
        f(j,0,m) {
            if(!vis[i][j]) {
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt;

}