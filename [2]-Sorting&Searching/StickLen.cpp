#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/*
5 * x = n1 + n2 + n3 + n4 + n5
|x1 + c1| + |x2 + c2| + |x3 + c3| + ...
|c1| + |c2| + |c3| + ...

*/

vector <long long> a;

int main() {
    long long n, x; cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> x;
        a.push_back(x);
    } 

    sort(a.begin(), a.end());
    long long median = a[n/2], ret = 0;

    for(int i=0; i<n; i++) {
        ret += abs(a[i]-median);
    }
    cout << ret;
}