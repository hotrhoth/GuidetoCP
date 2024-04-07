#include <iostream>
using namespace std;

#define ll long long
#define f(i,a,b) for(int i=a; i<b; i++)

const ll mod = 1e9+7;
const ll two_inverse = (mod+1)/2;

ll solve(ll st, ll e) {
    return (((e-st+1)%mod)*((st+e)%mod))%mod
        *two_inverse%mod;
}
int main() {
    ll n; cin >> n;
    ll ret = 0, at = 1;
    while(at<=n) {
        ll val = n/at;
        ll last_same = n/val;
        ret = (ret+val*solve(at, last_same))%mod;
        at = last_same+1;
    }
    cout << ret;
}