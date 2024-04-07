#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void outVP(vector <pair<int, int>> res, int n) {
    for(int i=0; i<n; i++)
        printf("{%d, %d} ", res[i].first, res[i].second);
    cout << "\n";
}

int main() {
    // sweep Line
    vector <pair<int, int>> res = {{1, 5}, {1, 2}, {2, 4}, {3, 7}, {6, 8}};
    int n = res.size(), ret = 0;
    sort(res.begin(), res.end());
    outVP(res, n);
    int arr[12*2] = {0};

    for(int i=0; i<n; i++) {
        arr[res[i].first]++;
        arr[res[i].second]--;
    }
    
    for(int i=0; i<24; i++) cout << arr[i] << " ";
    cout << "\n";

    int sum = 0;

    for(int k=0; k<24; k++) {
        // only contain array[k] or max(k-1) + array[k]
        sum = max(arr[k], sum + arr[k]);
        ret = max(ret, sum);
    }

    cout << ret << "\n";


    
    // scheduling Events
    // Tasks and Deadlines
}