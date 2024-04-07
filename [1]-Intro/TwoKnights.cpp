#include <iostream>
using namespace std;

int main() {
    long long n, res;
    cin >> n;
    for(long long i=1; i<=n; i++) {
        res = (i * i * (i * i - 1)) / 2 - 4 * (i - 1) * (i - 2);
        cout << res << "\n";
    }
    
}