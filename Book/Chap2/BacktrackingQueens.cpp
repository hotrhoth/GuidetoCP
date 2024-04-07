#pragma GCC target ("arch=sandybridge")
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int cnt;
#define n 8
bool col[n+1], diag1[n+1], diag2[n+1];

void search(int k) {
    if(k==n) {
        cnt++;
        return;
    }
    for(int x=0; x<n; x++) { //  row by row
        if(col[x] || diag1[x+k] || diag2[x-k+n-1]) continue;
        col[x] = diag1[x+k] = diag2[x-k+n-1] = 1;
        search(k+1);
        col[x] = diag1[x+k] = diag2[x-k+n-1] = 0;
    }  
}
int main() {
    search(0);
    cout << cnt;
}