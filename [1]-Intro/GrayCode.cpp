#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    for(int x=0; x<1<<n; x++) {
        for(int k=n-1; k>=0; k--) {
            if(x&(1<<k)) cout << "1";
            else cout << "0";
        }
        cout << "\n";
    }
    
}