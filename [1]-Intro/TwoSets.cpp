#include <iostream>
using namespace std;

int main() {
    long long n, res;
    cin >> n;
    res = n * (n + 1) / 2;
    if(res&1) cout << "NO";
    else {
        cout << "YES\n";
        // 1..n
        // so chan: 4n + 2, 4n + 4
        /*
        1 2 3 4
        -> n//2 // 2 -> 1 4, 2 3
        1 2 3 4 5
        -> NO
        1 2 3 4 5 6
        -> NO
        1 2 3 4 5 6 7
        -> (n+1)/2/2 -> 1 7 6, 2 3 5 4 
        1 2 3 4 5 6 7 8 9 10 11
        -> 1 11 2 10 9, 
        */
        long long t = 1 + n;
        if(n%4==0) {
            int x = n / 4;
            // x cap
            cout << x * 2 << "\n";
            for(int i=1; i<=x; i++)
                cout << i << " " << t - i << " ";
            cout << "\n";

            cout << x * 2 << "\n";
            for(int i=1; i<=x; i++)
                cout << i + x << " " << t - (i + x) << " ";
        }
        else {
            // (n+1)//4
            int x = (n + 1) / 4;
            cout << (x - 1) * 2 + 1 << '\n';
            int i = 0;
            for(i=1; i<=(x - 1); i++)
                cout << i << " " << t - i << " ";
            cout << t-i << "\n";
            
            int tmp = t-i;
            cout << n - ((x - 1) * 2 + 1) << "\n";
            for(; i<tmp; i++)
                cout << i << " " ;
            cout << "\n";
        }
    }


}
