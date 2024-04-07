#include <bits/stdc++.h>
using namespace std;

#define f(i,a,b) for(int i=a; i<b; i++)

int main() {
    int n, x; cin >> n >> x;
    vector <int> values(n);
    f(i,0,n) cin >> values[i];
    map<int, pair<int,int>> valuestopos;
    f(i,0,n) {
        f(j,i+1,n) {
            if(valuestopos.count(x-values[i]-values[j])) {
                cout << i+1 << " " << j+1 << " "
                    << valuestopos[x-values[i]-values[j]].first+1 << " "
                    << valuestopos[x-values[i]-values[j]].second+1;
                return 0;
            }
        }
        f(j,0,i) valuestopos[values[i]+values[j]] = {i,j};
    }
    cout << "IMPOSSIBLE";

}