#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void foo(vector <long long> &v, int n) {
    long long x;
    for(int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
}

int main() {
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> a, b;
   
   foo(a, n); foo(b, m);
   long long ret = 0;
   int i = 0, j = 0;
   while(i<n && j<m) {
    if(a[i] >= (b[j]-k) && a[i] <= (b[j]+k)) {
        ret++;
        i++; j++;
    } 
    else if(a[i] < (b[j]-k)) i++;
    else if(a[i] > (b[j]+k)) j++;
   }
   cout << ret;
}