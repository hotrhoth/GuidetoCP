#include <iostream>
using namespace std;

const int N = 100;
int arr[N][N];

int solve(int a, int b) {
    int cnt = 0;
    for(int i=0; i<N; i++)
        if(arr[a][i]==1 && arr[b][i]==1)
            cnt++;
    return cnt*(cnt-1)/2;
}

int main() {
    int ans = 0;
    for(int a=0; a<N; a++)
        for(int b=0; b<N; b++)
            ans += solve(a,b);
}