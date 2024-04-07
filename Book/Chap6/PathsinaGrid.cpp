#include <iostream>
using namespace std;

const int N = 1000;

int main() {
    int sum[N][N];
    int value[N][N];

    int n = 5;

    for(int i=0; i<=n; i++) {
        sum[0][i] = sum[i][0] = 0;
    }
    // only move down and right
    for(int y=1; y<=n; y++) {
        for(int x=1; x<=n; x++) {
            sum[y][x] = max(sum[y-1][x], sum[y][x-1]) + value[y][x];
        }
    }
}