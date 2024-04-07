#include <iostream>
#include <ctime>

using namespace std;

int sieve(int n) {
    for(int x=2; x<=n; x++) {
        if(sieve[x]) continue;
        for(int u=2*x; u<=n; u+=x) {
            sieve[u] = 1;
        }
    }
    return 0;
}
// ax + by = gcd(a, b)
// ax + by = d -> chi co nghiem khi d la boi cua gcd
/*
(x, y) -> (x + kb/gcd, y - ka/gcd)
*/
tuple <int, int, int> gcd(int a, int b) {
    if(b==0) return {1, 0, a};
    else {
        int x, y, g;
        tie(x, y, g) = gcd(b, a%b);
        return {y, x-(a/b)*y, g};
    }
}