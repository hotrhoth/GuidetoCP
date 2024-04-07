#include <iostream>
using namespace std;

const int N = 100;
int link[N], size[N];

int find(int x) {
    while(x!=link[x]) x=link[x];
    return x;
}

bool same(int a, int b) {
    return find(a)==find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(size[a]<size[b]) swap(a,b);
    size[a] += size[b];
    link[b] = a;
}

int path(int x) {
    if(x==link[x]) return x;
    return link[x]=path(link[x]);
}

int main() {
    for(int i=1; i<N; i++) link[i] = i;
    for(int i=1; i<N; i++) size[i] = 1;
}