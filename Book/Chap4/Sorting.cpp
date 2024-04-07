#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct point {
    int x, y;
    bool operator< (const point &p) {
        if(x == p.x) return y < p.y;
        else return x < p.x;
    }
};

bool comp(string a, string b) {
    if(a.size() == b.size()) return a < b;
    else return a.size() < b.size();

}
void outArr(int array[], int n) {
    for(int i=0; i<n; i++) cout << array[i] << " ";
    cout << "\n";
}

void BubbleSort(int array[], int n) {
    // O(n^2)
    for(int i=0; i<n; i++)
        for(int j=0; j<n-1; j++)
            if(array[j] > array[j+1])
                swap(array[j], array[j+1]);
}

int main() {
    int array[] = {1, 3, 8, 2, 9, 2, 5, 6};
    // BubbleSort(array, 8);
    outArr(array, 8);
}