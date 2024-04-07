#include <bits/stdc++.h>
using namespace std;

#define pii pair<long long, long long> 
#define vii vector<pii>
#define ll long long
#define f(i,a,b) for(int i=0; i<n; i++)

int main() {
    ll n, k; cin >> n >> k;
    priority_queue <pii> l; // max_heap
    priority_queue <pii, vii, greater<pii>> r; //min_heap;
    ll a[n+1];
    f(i,0,n) cin >> a[i];
    ll m = (k+1)/2, lsum = 0, rsum = 0, j = 0; // j la so luong cua l
    f(i,0,n) {
        while(!r.empty() && r.top().second<=i-k) r.pop();
        while(!l.empty() && l.top().second<=i-k) l.pop();
        if(j<m) {
            r.push({a[i], i}); rsum += a[i];
            l.push(r.top()); lsum += r.top().first;
            rsum -= r.top().first; r.pop();
            j++;
        }
        else {
            l.push({a[i], i}); lsum += a[i];
            r.push(l.top()); rsum += l.top().first;
            lsum -= l.top().first; l.pop();
        }
        while(!r.empty() && r.top().second<=i-k) r.pop();
        while(!l.empty() && l.top().second<=i-k) l.pop();
        if(i < k-1) continue;
        ll med = l.top().first;
        cout << (m*med - lsum + rsum - (k-m)*med) << " ";
        if(a[i-k+1] <= l.top().first) {
            j--; lsum -= a[i-k+1];
        }
        else rsum -= a[i-k+1];
    }
}