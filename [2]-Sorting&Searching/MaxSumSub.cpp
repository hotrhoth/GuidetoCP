#include <iostream>
#include <algorithm>
using namespace std;

long long arr[200005];

int main() {
    int n; cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    long long ret = -1e9, sum = 0;
    
    for(int i=0; i<n; i++) {
        sum = max(arr[i], sum + arr[i]);
        ret = max(ret, sum);
    }
    cout << ret;
}