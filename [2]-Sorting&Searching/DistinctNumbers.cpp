#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

vector <long long> v;

int main() {
    long long n, ret = 0; cin >> n;
    
    while(n--) {
        long long x; cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());

    for(auto i = v.begin(); i != v.end(); ++i) {
        if(*i!=*(i+1)) ret++;
    }
    cout << ret;
}
