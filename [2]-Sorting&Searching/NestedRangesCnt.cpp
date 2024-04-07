#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define f(i,a,b) for(int i=a; i<b; i++)

struct range {
    int l, r, index;
    bool operator < (const range &other) const {
        if(l == other.l) return r > other.r;
        return l < other.l;
    }
};

int main() {
    int n; cin >> n;
    vector <range> ranges(n);
    vector <int> contained(n, 0), contains(n, 0);
    ordered_set<pair<int,int>> rightBoundaries;

    f(i,0,n) {
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].index = i;
    }

    sort(ranges.begin(), ranges.end());

    f(i,0,n) {
        rightBoundaries.insert({ranges[i].r, -1*i});
        contained[ranges[i].index] = rightBoundaries.size()
            - rightBoundaries.order_of_key({ranges[i].r, -1*i}) - 1;
    }
    rightBoundaries.clear();
    for(int i=n-1; i>=0; i--) {
        rightBoundaries.insert({ranges[i].r, -1*i});
        contains[ranges[i].index] = rightBoundaries.order_of_key({ranges[i].r, -1*i});
    }
    f(i,0,n) cout << contains[i] << " ";
    cout << "\n";
    f(i,0,n) cout << contained[i] << " ";

}