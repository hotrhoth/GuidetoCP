#include <iostream>
using namespace std;

// src a, aux b, des c
void solve(int a, int b, int c, int n) {
    if(n==0) return;
    solve(a,c,b,n-1);
    cout << a << " " << c << "\n";
    // move from src -> aux
    solve(b,a,c,n-1);
}

int main() {
    /*
    .
   ..
  ...
    1   2   3
    */
    int n; cin>>n;
    cout << (1<<n)-1<<"\n";
    solve(1,2,3,n);

}