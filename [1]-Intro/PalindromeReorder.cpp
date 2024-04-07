#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    string s; cin >> s;
    // string s = "SQAADSDTQ";
    int c[26] = {}, u = 0, trace = 0;
    for(char d : s)
        ++c[d-'A'];
    for(int i=0; i<26; i++) {
         u+=c[i]&1;
         if(c[i]&1)
            trace = i;
    }
       
    if(u>1) {
        cout << "NO SOLUTION";
        return 0;
    }
    string t;
    for(int i=0; i<26; i++)
        if(c[i]&1^1)
            for(int j=0; j<c[i]/2; j++)
                t+=(char)('A'+i);
    cout << t;

    if(c[trace]&1)
        for(int j=0; j<c[trace]; j++)
            cout << (char)('A'+trace);
            
    reverse(t.begin(), t.end());
    cout << t;

}