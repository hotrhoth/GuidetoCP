#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int p[] = {2, 3, 7};
int k;

bool valid(int x) {
    return (x/p[0] + x/p[1] + x/p[2])>=k;
}

int main() {
    int arr[] = {1, 3, 3, 4, 5, 5, 6, 9, 10, 12, 12, 15};
    int n = sizeof(arr)/sizeof(int), x=9;
    
    // First method
    int a = 0, b = n - 1;
    while(a<=b) {
        int k = (a+b)/2; // already round down
        if(arr[k]==x);
        if(arr[k]<x) a = k+1;
        else b = k-1;
    }

    // Second method
    for(b = n/2; b>=1; b/=2) {
        while(k+b<n && arr[k+b]<=x) k+=b; // luon + b de nhay toi
    }
    if(arr[k]==x) cout << k << "\n";

    
    k = 8, n = 3; 
    x = -1;
    for(b = k/p[0]; b>=1; b/=2) {
        while(!valid(x+b)) x+=b;
    }
    k = x+1;
    cout << k;
}