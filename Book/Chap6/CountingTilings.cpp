#include <iostream>
#include <cmath>
using namespace std;


#define N 1000
const int inf = 1e6;

int main() {
    int n, m;
    cin >> n >> m;
    if(n&1 && m&1) {
        cout << "0";
        return 0;
    }
    long double pi, a1, b1, ret=1;

    pi = acos(-1);
    a1 = pi * 1.0 / (n+1);
    b1 = pi * 1.0 / (m+1);

    const int mod = (1e9+7);

    for(int a=1; a <= n/2; a++) {
        for(int b=1; b <= m/2; b++) {
            ret *= 4*(cos(a*a1)*cos(a*a1) + cos(b*b1)*cos(b*b1));
        }
    }

    cout << ret << "\n";
    

}