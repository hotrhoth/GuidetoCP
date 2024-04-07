#include <iostream>
using namespace std;

#define N 100

int tree[N]; // Binary Indexed Tree (Fenwick Tree)

int sum(int k) {
    int s = 0;
    while(k>=1) {
        s += tree[k];
        k -= k&-k;
    }
    return s;
}

void add(int k, int x) {
    while(k<=N) {
        tree[k] += x;
        k += k&-k;
    }
}