#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector <int> values(n);
    int maxVal = 0;
    for(int i=0; i<n; i++) {
        cin >> values[i];
        maxVal = max(values[i], maxVal);
    }

    long long low = maxVal, hi = 1e18, ret = 1e18;
    while(low <= hi) {
        long long mid = (low+hi)/2;
        int blocks = 1;
        long long sum = 0;
        for(int i=0; i<n; i++) {
            if(sum + values[i] > mid) {
                sum = 0;
                blocks++;
            }
            sum += values[i];
        }
        if(blocks > k) low = mid+1;
        else {
            if(mid < ret) ret = mid;
            hi = mid-1;
        }
    }
    cout << ret;
}