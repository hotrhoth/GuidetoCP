#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int maxn = 200005;
int values[maxn], pos[maxn];
set <pair<int, int>> pairs;

int main() {
    int n, m; cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> values[i];
        pos[values[i]] = i;
    }
    
    int ret = 1;
    for(int i=1; i<n; i++) ret += pos[i] > pos[i+1];

    int a, b;
    while(m--) {
        cin >> a >> b;
        if(values[a]+1<=n) pairs.insert({values[a],values[a]+1});
        if(values[a]-1>=1) pairs.insert({values[a]-1,values[a]});
        if(values[b]+1<=n) pairs.insert({values[b],values[b]+1});
        if(values[b]-1>=1) pairs.insert({values[b]-1,values[b]});
        for(auto x: pairs) 
            ret -= pos[x.first] > pos[x.second];
        swap(values[a], values[b]);
        pos[values[a]] = a; pos[values[b]] = b;
        for(auto x: pairs) ret += pos[x.first] > pos[x.second];
        cout << ret << "\n";
        pairs.clear();
    }
}