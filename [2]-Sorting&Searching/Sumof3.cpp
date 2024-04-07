#include <bits/stdc++.h>
using namespace std;

#define f(i,a,b) for(int i=a; i<b; i++)

int main() {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> a(n);
    f(i,0,n) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    for(int i=0; i<n; i++) {
        int x2 = x - a[i].first;
        for(int k = i+1, j=n-1; k<j; k++) {
            while(a[k].first+a[j].first > x2) j--;
            if(k<j && a[k].first+a[j].first==x2) {
                cout << a[i].second+1 << " " << a[j].second+1 << " " << a[k].second+1;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE";
}