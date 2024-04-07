#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define f(i,a,b) for(int i=a; i<b; i++)

int main() {
    ll n, k; cin >> n >> k;
    ll a[22];
    f(i,0,k) cin >> a[i];
    vector <ll> countbynum(k+1);
    fill(countbynum.begin(), countbynum.end(), 0);
    ll ret = 0;
    f(i,0,(1ll<<k)){
        int numofDiv = 0;
        ll tmp = n;
        f(j,0,k) {
            if((1<<j)&i) {
                numofDiv++;
                tmp /= a[j];
            }
        }
        countbynum[numofDiv] += tmp;
    }
    f(i,1,k+1) 
        if(i&1) ret += countbynum[i];
        else ret -= countbynum[i];
    cout << ret;
}