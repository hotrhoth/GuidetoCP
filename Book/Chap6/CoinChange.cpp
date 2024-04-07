#include <iostream>
using namespace std;


#define N 1000
const int inf = 1e6;

int main() {
    int value[N], first[N] = {0};
    int coins[] = {1, 3, 4};
    value[0] = 0;
    for(int i=1; i<N; i++) {
        value[i] = inf;
        for(auto c : coins) {
            if(i-c>=0 && value[i-c]+1 < value[i]) {
                value[i] = value[i-c]+1;
                first[i] = c;
            }
        }
    }

    int x = 123;

    while(x > 0) {
        cout << first[x] << " ";
        x -= first[x];
    }
    
    // Counting problems


}