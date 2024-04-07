#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    // Sliding window
    vector <int> values(n);
    for(int i=0; i<n; i++) cin >> values[i];
    int i = 0, j = 0; long long sum = 0, cnt = 0;
    while(i < n) {
        sum += values[i];
        while(sum >= x) {
            if(sum == x) cnt ++;
            sum -= values[j];
            j++;
        }
        i++;
    }

    cout << cnt;
}