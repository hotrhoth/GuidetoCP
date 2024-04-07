#include <iostream>
#include <complex>
using namespace std;

typedef long double C;
typedef complex<C> P;
#define X real()
#define Y imag()

int main() {
    P p = {4,2};
    cout << p.X << " " << p.Y << "\n";
    cout << abs(p);
}