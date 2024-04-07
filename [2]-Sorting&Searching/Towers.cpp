#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n; cin >> n;
    multiset <int> k;
    int x;
    for(int i=0; i<n; i++) {
        cin >> x;
        auto it = k.upper_bound(x);
        if(it==k.end()) k.insert(x);
        else {
            k.erase(it);
            k.insert(x);
        }
    }
    cout << k.size();
}