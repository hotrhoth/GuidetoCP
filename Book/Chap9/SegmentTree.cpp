#include <iostream>
using namespace std;

int tree[] = {0, 39, 22, 17, 13, 9, 9, 8, 5, 8, 6, 3, 2, 7, 2, 6};
int n = 8;

int sum(int a, int b) {
    a += n; b += n;
    int s = 0;
    while(a<=b) {
        if(a%2==1) // con phai thi nhay len
            s += tree[a++];
        if(b%2==0) // con trai thi nhay len
            s += tree[b--];
        a/=2; b/=2; // tu nhay 
    }
    return s;
}

void add(int k, int x) {
    k += n;
    tree[k] += x; // update bot value
    for(k/=2; k>=1; k/=2) {
        tree[k] = tree[2*k] + tree[2*k+1];
    }
}

int main() {
    cout << sum(2, 7) << "\n";
}