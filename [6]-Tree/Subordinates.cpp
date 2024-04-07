#include <iostream>
#include <vector>
using namespace std;

#define f(i,a,b) for(int i=a; i<b; i++)

const int maxn = 2e5 + 2;
vector <vector<int>> adj(maxn);
vector <int> subtree_size(maxn);

int solve(int node) {
    if(adj[node].size()==0) return 1;
    f(i,0,adj[node].size()) {
        // cout << node << "\n";
        subtree_size[node] += solve(adj[node][i]);
    } 
    return subtree_size[node]+1;
}

int main() {
    int n, x; cin >> n;
    for(int i=2; i<=n; i++) {
        cin >> x;
        adj[x].push_back(i);
    }
    /*
    f(i,0,n+1) {
        cout << i << ": ";
        f(j,0,adj[i].size()) cout << adj[i][j] << " ";
        cout << "\n";
    }
    */
    
    solve(1);
    f(i,1,n+1) cout << subtree_size[i] << " ";
        
    
}