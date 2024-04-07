#include <iostream>
using namespace std;

long long appear[1000000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n, tmp;
    cin >> n;
    
    for(int i=1; i<n; i++){
        cin >> tmp;
        appear[tmp] = 1;
    }

    for(int i=1; i<=n; i++) {
        if(!appear[i]) {
            cout << i;
            return 0;
        }
    }
}