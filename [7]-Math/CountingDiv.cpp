#include <iostream>
using namespace std;

const int maxn = 1e6+2;
#define f(i,a,b) for(int i=a; i<b; i++)
int main() {
    int n, x;
    cin >> n;
    long long d[maxn] = {0};
    f(i,1,maxn)
        for(int j=i; j<maxn; j+=i)
            d[j]++; // i la divisor
    // d[18] -> i=1
    while(n--) {
        cin >> x;
        cout << d[x] << "\n";
    }
}