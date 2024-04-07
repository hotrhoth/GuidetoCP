#include <iostream>
using namespace std;

vector <vector<int>> adj{{1, 2, 3}, {0, 4, 5}, {0}, {0, 6}, {1}, {1, 7}, {3}, {5}};

class LCA {
public:
    vector <int> Nodes, Depth; // , last;
    int segment_tree_size;
    vector <pair<int, int>> segment_tree;

    LCA(vector <vector<int>> &adj) {
        int N = adj.size();
        Nodes.resize(2*N-1);
        Depth.resize(2*N-1);
        // last.resize(N);
        int index = 0;
        vector <bool> visited(N);
        tour(adj, 0, 1, index, visited);
    }
    void tour(vector <vector<int>> &adj, int current_node, int current_depth,
        int &index, vector <bool> &visited) {
        Nodes[index] = current_node;
        Depth[index] = current_depth;
        // last[current_node] = index;
        visited[current_node] = true;
        ++index;
        for(int child: adj[current_node]) {
            if(!visited[child]) {
                tour(adj, child, current_depth+1, index, visited);
                Nodes[index] = current_node;
                Depth[index] = current_depth;
                // last[current_node] = index;
                ++index;
            }
        }
    }
    void display() {
        for(int i=0; i<Nodes.size(); i++)
            cout << Nodes[i] << " ";
        cout << "\n";
        for(int i=0; i<Depth.size(); i++)
            cout << Depth[i] << " ";
        cout << "\n";
        /*
        for(int i=0; i<last.size(); i++)
            cout << last[i] << " ";
        cout << "\n";
        */
        
    }
};

int main() {
    LCA lca(adj);
    lca.display();
}