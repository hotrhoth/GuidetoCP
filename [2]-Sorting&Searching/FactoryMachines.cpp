#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define f(i,a,b) for(int i=a; i<b; i++)

int main() {
    int n, t; cin >> n >> t;
    // 3 * x + 2 * y + 5 * z min
    // (x + y + z) = t
    // ret = max(3x, 2y, 5z)
    vector <int> machines(n);
    f(i,0,n) cin >> machines[i];
    ll low = 0, hi = 1e18, ans = 1e18;
    while(low<=hi) {
        ll mid = (low+hi)/2;
        ll products = 0;
        f(i,0,n) products += min(mid/machines[i], (ll)1e9);
        if(products >= t) {
            if(mid < ans) ans = mid;
            hi = mid - 1;
        }
        else low = mid + 1;
    }
    cout << ans;

}