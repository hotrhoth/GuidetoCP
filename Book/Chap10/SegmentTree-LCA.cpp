#include <iostream>
using namespace std;

class LCA {

    /**
     * Lowest Common Ancestor for multiple queries
     * Uses Segment tree - O(N) build time + O(log N) query time
     * Parameters for Constructor: vector<vector<int>> adj_list; (undirected)
     */

    public:
    vector<int> Nodes, Depth, last;
    int segment_tree_size;
    vector<pair<int, int>> segment_tree;

    LCA(vector<vector<int>>& adj) {
        int N = adj.size();
        Nodes.resize(2 * N - 1);
        Depth.resize(2 * N - 1);
        last.resize(N);
        int index = 0;
        vector<bool> visited(N);
        tour(adj, 0, 0, index, visited);
        build_segment_tree();
    }

    void tour(vector<vector<int>>& adj, int current_node, int current_depth, int& index, vector<bool>& visited) {
        Nodes[index] = current_node;
        Depth[index] = current_depth;
        last[current_node] = index;
        visited[current_node] = true;
        ++index;
        for(int child: adj[current_node]) {
            if(!visited[child]) {
                tour(adj, child, current_depth + 1, index, visited);
                Nodes[index] = current_node;
                Depth[index] = current_depth;
                last[current_node] = index;
                ++index;
            }
        }
    }

    void build_segment_tree() {
        int N = Nodes.size();
        for(; (N & (N - 1)) != 0; N++); // need N to be power of 2

        Depth.resize(N, INT_MAX);
        segment_tree_size = N;
        segment_tree.resize(2 * N);

        for(int i = 2 * N - 1; i >= N; i--) {
            segment_tree[i] = make_pair(i, Depth[i - N]);
        }

        for(int i = N - 1; i > 0; i--) {
            if(segment_tree[2 * i].second < segment_tree[2 * i + 1].second) {
                segment_tree[i] = segment_tree[2 * i];
            }
            else {
                segment_tree[i] = segment_tree[2 * i + 1];
            }
        }
    }

    pair<int, int> segment_tree_query(int node, int node_lb, int node_ub, int query_lb, int query_ub) {
        if(node_lb > query_ub || node_ub < query_lb) {
            return make_pair(-1, INT_MAX);
        }
        else if(query_lb <= node_lb && node_ub <= query_ub) {
            return segment_tree[node];
        }
        else {
            pair<int, int> left_returned = segment_tree_query(2 * node, node_lb, (node_lb + node_ub) / 2, query_lb, query_ub);
            pair<int, int> right_returned = segment_tree_query(2 * node + 1, (node_lb + node_ub) / 2 + 1, node_ub, query_lb, query_ub);
            if(left_returned.second < right_returned.second) {
                return left_returned;
            }
            else {
                return right_returned;
            }
        }
    }

    int find_lca(int a, int b) {
        int index_a = last[a];
        int index_b = last[b];
        if(index_a > index_b) {
            swap(index_a, index_b);
        }
        index_a += segment_tree_size;
        index_b += segment_tree_size;
        pair<int, int> returned = segment_tree_query(1, segment_tree_size, 2 * segment_tree_size - 1, index_a, index_b);
        int lca_index = returned.first - segment_tree_size;
        return Nodes[lca_index];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 0;
    cin >> N;
    vector<vector<int>> adj(N);
    for(int i = 0; i < N - 1; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        // Uncomment the following line for trees indexed from 1
        // a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    LCA lca(adj);
    int n_queries = 0;
    cin >> n_queries;
    for(; n_queries > 0; n_queries--) {
        int a = 0, b = 0;
        cin >> a >> b;
        cout << lca.find_lca(a, b) << '\n';
    }
    return 0;
}