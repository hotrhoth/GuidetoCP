#include <iostream>
using namespace std;

#define ll long long
#define f(i,a,b) for(int i=a; i<b; i++)

ll n;
const int maxn = 1e6+2;

int main() {
    cin >> n;
    ll x[n], cnt[maxn] = {};
    f(i,0,n) {
        cin >> x[i];
        cnt[x[i]]++;
    }
    
    for(int i=1e6;i>=1;i--)
    {
        // i la div
        ll d=0;
        for(int j=i;j<=1e6;j+=i) d+=cnt[j];

        if(d>=2)
        {
            cout<<i;
            return 0;
        }
    }

}