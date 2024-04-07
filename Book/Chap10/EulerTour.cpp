#include <iostream>
using namespace std;

#define n 5
vector<vector<int>> adj{{1, 2}, {0}, {0, 3, 4}, {2}, {2}};
vector <int> nodeid(2*n);
vector <int> height(n);
int id = 0;
bool vis[n];

void eulerTree(int u, int s, int &index)
{
    vis[u] = 1;
    
    if(u!=s)
    height[u] = height[s] + 1;
    nodeid[index++] = u;
    for (auto it : adj[u]) {
        if (!vis[it]) {
            eulerTree(it, u, index);
            // depth[index] = height[u];
            nodeid[index++] = u;
            
        }
        
    }
    
}
 

int main() {
    height[0] = 1;
    eulerTree(0, 0, id);
    for(int i=0; i<nodeid.size()-1; i++) {
        cout << nodeid[i] << " ";
    }
    cout << "\n";
    for(int i=0; i<height.size(); i++) {
        cout << height[i] << " ";
    }
    // cout << depth.size() << " " << nodeid.size() << "\n";

}