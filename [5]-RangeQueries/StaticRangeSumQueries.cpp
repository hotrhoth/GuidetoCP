#include <iostream>
using namespace std;

#define f(i,a,b) for(int i=a; i<b; i++)

const int maxn = 200005;
int n, q;
long long x[maxn];
long long prep[maxn];

int main() {
    int a, b;
    cin >> n >> q;
    // prep.push_back(0);
    f(i,1,n+1) {
        cin >> x[i];
        prep[i] = prep[i-1]+x[i];
    }

    f(i,0,q) {
        cin >> a >> b;
        cout << prep[b]-prep[a-1]<<"\n";
    }

}