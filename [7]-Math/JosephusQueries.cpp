#include <iostream>
using namespace std;

#define ll long long
long long q, k, n;

ll f(ll n, ll k) {
    if(n==1) return 1;
    if(k<=(n+1)/2) {
        if(2*k>n) return (2*k)%n;
        else return 2*k;
    }

    ll tmp = f(n/2, k-(n+1)/2);
    if(n&1) return 2*tmp+1;
    else return 2*tmp-1;
}
int main() {
    cin >> q;
    while(q--) {
        cin >> n >> k;
        cout << f(n,k) << "\n";
    }
}