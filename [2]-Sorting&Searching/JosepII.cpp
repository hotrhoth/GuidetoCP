#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, 
tree_order_statistics_node_update> indexed_set;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    indexed_set s;
    long long n, k; cin >> n >> k;
    for(long long i=1; i<=n; i++) s.insert(i);
    long long ind = k%n;
    while(n--) {
        auto y = s.find_by_order(ind);
        cout << *y << " ";
        s.erase(y);
        if(n) ind = (ind%n+k)%n;
    }
}