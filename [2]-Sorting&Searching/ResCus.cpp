#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector <pair <int, int>> v;
    int a, b;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b, -1});
    }
    sort(v.begin(), v.end());
    int cur = 0, ret = 0;
    for(auto t : v) {
        cur += t.second;
        ret = max(ret, cur);
    }
    cout << ret;
    

}