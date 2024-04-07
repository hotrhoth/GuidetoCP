#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    vector <int> values(n);
    for(int i=0; i<n; i++) cin >> values[i];
    long long sum = 0, cnt = 0;
    map <long long, int> seen;
    seen[0]++;
    // 5 3 2 6 7 8
    for(int i=0; i<n; i++) {
        sum += values[i];
        cnt += seen[sum-x];
        seen[sum]++;
    }
    cout << cnt;
}