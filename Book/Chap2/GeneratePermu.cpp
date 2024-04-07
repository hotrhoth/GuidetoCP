#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define n 3

vector <int> permu;
bool chosen[n+1];

void search() {
    if(permu.size()==n) {
        for(int i=0; i<n; i++) cout << permu[i] << " ";
        cout << "\n";
    }
    else {
        for(int i=1; i<=n; i++) {
            if(chosen[i]) continue;
            chosen[i] = true;
            permu.push_back(i);
            search();
            permu.pop_back();
            chosen[i] = false;
        }
    }
}

// while(next_permutation(permu.begin(), permu.end()));

int main() {
    search();
}