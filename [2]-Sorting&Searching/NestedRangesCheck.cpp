#include <bits/stdc++.h>
using namespace std;

#define ll long long 
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
    vector <bool> contained(n, false), contains(n, false);
    f(i,0,n) {
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].index = i;
    }

    sort(ranges.begin(), ranges.end());
    int maxEnd = 0, minEnd = 1e10;
    
    f(i,0,n) {
        if(ranges[i].r <= maxEnd)
            contained[ranges[i].index] = true;
        maxEnd = max(maxEnd, ranges[i].r);
    }

    for(int i=n-1; i>=0; i--) {
        if(ranges[i].r >= minEnd)
            contains[ranges[i].index] = true;
        minEnd = min(minEnd, ranges[i].r);
    }

    f(i,0,n) cout << contains[i] << " ";
    cout << "\n";
    f(i,0,n) cout << contained[i] << " ";
}