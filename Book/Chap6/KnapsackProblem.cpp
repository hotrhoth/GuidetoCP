#include <iostream>
using namespace std;

const int N = 1000;

// possible(x, k) = (possible(x-w[k], k-1) || possible(x, k-1))

int main() {
    int weights[] = {1, 3, 3, 5};
    int n = sizeof(weights)/sizeof(int);
    int m = 0;
    for(int i=0; i<n; i++) m+=weights[i];
    
    bool possible[N];

    possible[0] = true;
    for(int k=0; k<n; k++) {
        for(int x=m-weights[k]; x>=0; x--) {
            possible[x+weights[k]] |= possible[x];
        }
    }

    for(int i=0; i<m+1; i++)
    cout << possible[i] << " ";


}