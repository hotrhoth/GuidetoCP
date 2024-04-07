#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long
#define f(i,a,b) for(int i=a; i<b; i++)

const int maxn = 1e6 + 2;
int spf[maxn];

void sieve() {
    spf[0] = 1;
    f(i,1,maxn) spf[i] = i;
    f(i,2,sqrt(maxn)+1) {
        // uoc nho nhat khac 1, i
        if(spf[i]==i) {
            for(int j=i*i;j<maxn; j+=i) {
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
}

ll cnt[maxn];

int main() {
    ll n; cin >> n;
    ll ret = 0; sieve();

    f(i,0,n) {
        ll x; cin >> x;
        vector <ll> v;
        while(x>1) {
            int y = spf[x];
            v.push_back(y);
            while(x%y==0) x/=y;
        }
        int k = v.size();
        f(s,1,1<<k) {
            int p = 1;
            f(j,0,k)
                if(s>>j&1) p *= v[j];
            int sign = -1;
            if(__builtin_popcount(s)&1) sign = 1;
            ret += sign*cnt[p];
            cnt[p]++;
        }
    }
    cout << n*(n-1)/2-ret;
}