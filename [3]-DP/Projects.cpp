#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;

#define ll long long
#define f(i,a,b) for(int i=a; i<b; i++) 

struct prj {ll start,end,money;};

bool cmp(prj &p1, prj &p2) {
    if(p1.end!=p2.end) return p1.end<p2.end;
    return p1.money<p2.money;
}
// n prjs, st end money
// only attend 1 prj during a day -> max money
int main() {
    ll n; cin >> n;
    vector <prj> v(n);
    f(i,0,n) {
        cin >> v[i].start >> v[i].end >> v[i].money;
    }
    sort(v.begin(), v.end(), cmp);

    set<pair<ll,ll>> ends;
    ends.insert({0,0});
    ll ans = 0;
    f(i,0,n) {
        auto t = ends.lower_bound({v[i].start, -1});
        t--;
        ans = max(ans, v[i].money+t->second);
        ends.insert({v[i].end, ans});
    }
    cout << ans;
}