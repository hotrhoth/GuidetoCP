#include <iostream>
using namespace std;

#define ll long long
const int mod = 1e9+7;

ll solve(ll a, ll b) {
    if(b==0) return 1;
    // if(b==1) return (a%mod);
    ll tmp = solve(a,b/2);
    if(b&1) return (((tmp*tmp)%mod)*a)%mod;
    return (tmp*tmp)%mod;
    

}
int main() {
    ll n, a, b;
    cin >> n;
    while(n--) {
        cin >> a >> b;
        cout << solve(a,b) << "\n";
    }
}