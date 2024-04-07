#include <iostream>
#include <vector>
using namespace std;

int length[200005];

int main() {
    int n; cin >> n;
    /*
     vector <int> x(n);
    for(int i=0; i<n; i++) cin >> x[i];

    for(int k=0; k<n; k++) {
        length[k] = 1;
        for(int i=0; i<k; i++) {
            if(x[i] <= x[k])
                length[k] = max(length[k], length[i] + 1);
        }
    }
    cout << length[n-1];
    */

   vector <int> dp; int x;

   for(int i=0; i<n; i++) {
        cin >> x;
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if(it==dp.end()) dp.push_back(x); // <=
        else *it = x; // 
        
   }
   cout << dp.size();
    
}