#include <iostream>
#include <cmath>
using namespace std;

const int maxn = 2e5+2;
const int logn = 19;

int n, q, a, b, l, k, x[maxn][logn];

int main() {
    cin >> n >> q;
    for(int i=0; i<n; i++) cin >> x[i][0];

    for(int i=1; i<logn; i++)
        for(int j=0; j<=n-(1<<i); j++)
            x[j][i] = min(x[j][i-1], x[j+(1<<(i-1))][i-1]);
    while(q--) {
        cin >> a >> b;
        a--; b--;
        l = b-a+1;
        k = log2(l);
        cout << min(x[a][k], x[b-(1<<k)+1][k]) << "\n";
    }
}