#include <iostream>
using namespace std;

const int NODES = 1e7 + 5;
int id = 1, sum[NODES], pl[NODES], pr[NODES];

int query(int p, int l , int r, int i, int j) {
    if(i > r || j < l || !p) return 0;
    if(i <= l && r <= j) return sum[p];
    int m = (l + r) / 2;
    return query(pl[p], l, m, i, j) + query(pr[p], m + 1, r, i, j);
}

int update(int p, int l, int r, int i, int v) {
    if(!p) p = id++;
    if(l == r) {
        sum[p] = v;
        return p;
    }
    int m = (l + r) / 2;
    if(i <= m) 
        pl[p] = update(pl[p], l, m, i, v);
    else
        pr[p] = update(pl[p], m + 1, r, i, v);
    sum[p] = sum[pl[p]] + sum[pr[p]];
    return p;
}

int merge(int p1, int p2) {
    if(!p1) return p2;
    if(!p2) return p1;
    pl[p1] = merge(pl[p1], pl[p2]);
    pr[p1] = merge(pr[p1], pr[p2]);
    sum[p1] = sum[pl[p1]] + sum[pr[p1]];
    return p1;
}