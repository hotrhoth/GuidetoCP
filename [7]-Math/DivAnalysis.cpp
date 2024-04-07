#include <iostream>
using namespace std;

#define ll long long
#define f(i,a,b) for(int i=a; i<b; i++)

const ll mod = 1e9+7;

ll expo(ll base, ll pow) {
    ll ans = 1;
    while(pow) {
        if(pow&1) ans = ans * base % mod;
        base = base * base % mod;
        pow >>= 1;
    }
    return ans;
}

const int maxn = 1e5+2;
ll p[maxn], k[maxn];

int main() {
    ll n; cin >> n;
    f(i,0,n) cin >> p[i] >> k[i];
    ll cnt = 1, sum = 1, prod = 1, cnt_2 = 1;
    f(i,0,n) {
        cnt = cnt * (k[i]+1) % mod;
        sum = sum * (expo(p[i], k[i]+1)-1) % mod 
                * (expo(p[i]-1, mod-2)) % mod;
        // pi = pi-1 ^ (k[i]+1) * (x[i] ^ (k*(k+1)/2))^(cnt_i-1 % (mod-1))
        prod = expo(prod, k[i]+1) * 
                expo(expo(p[i], (k[i]*(k[i]+1)/2)), cnt_2)%mod;
        cnt_2 = cnt_2 * (k[i]+1) % (mod-1);
    }
    cout << cnt << " " << sum << " " << prod;
}