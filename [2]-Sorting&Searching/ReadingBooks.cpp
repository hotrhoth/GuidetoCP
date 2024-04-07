#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector <long long> books(n);
    long long sumof = 0;
    for(int i=0; i<n; i++) {
        cin >> books[i];
        sumof += books[i];
    }
    sort(books.begin(), books.end());
    cout << max(sumof, books[n-1]*2);
}