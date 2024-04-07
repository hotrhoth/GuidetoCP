#include <iostream>
using namespace std;

const int N = 10;

int main() {
    int x = 12, n = 5;
    int weight[] = {2, 3, 4, 5, 9};

    pair<int, int> best[1<<N];
    // initial value: n+1 rides are needed
    best[0] = {1, 0};
    for(int s=1; s<(1<<n); s++) {
        best[s] = {n+1, 0};
        
        for(int p=0; p<n; p++) {
            
            if(s&(1<<p)) {
                auto option = best[s^(1<<p)];
                if(option.second + weight[p] <= x) {
                    option.second += weight[p];
                }
                else {
                    // bc base best[0] = {1, 0}
                    option.first++;
                    option.second = weight[p];
                }
                best[s] = min(best[s], option);
            }
        }
    }

    cout << best[(1<<n)-1].first << "\n";
}