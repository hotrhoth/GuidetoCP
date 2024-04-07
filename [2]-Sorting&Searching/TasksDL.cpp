#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n; cin >> n;
    // a d
    // 0 
    vector <pair<ll,ll>> tasks(n);
    for(ll i=0; i<n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }
    sort(tasks.begin(), tasks.end());
    ll ret = 0;
    for(ll i=0; i<n; i++) {
        ret += tasks[i].second - (n-i)*tasks[i].first;
    }
    cout << ret;

}