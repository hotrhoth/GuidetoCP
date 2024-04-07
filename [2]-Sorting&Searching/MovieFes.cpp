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
        v.push_back({b, a});
    }
    sort(v.begin(), v.end());
    int cur_end = 0, ret = 0;
    for(auto x: v) {
        if(x.second >= cur_end) {
            cur_end = x.first;
            ret++;
        }
    }
    cout << ret;
}