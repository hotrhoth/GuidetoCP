#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x; cin >> n;
    int v[200005];

    for(int i=1; i<=n; i++) {
        cin >> x;
        v[x] = i; // luu vi tri cua gia tri
        // 3 2 5 1 4
    }
    
    int ret = 1;
    for(int i=1; i<n; i++) {
        if(v[i+1]<v[i])
            ret++;
    }
    cout << ret;
}