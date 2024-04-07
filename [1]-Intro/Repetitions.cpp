#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long ret = 1;

    string s;
    cin >> s;
    long long tmp = 1;
    for(int i=1; i<s.size(); i++) {
        if(s[i]==s[i-1]) {
            tmp++;
        }
        else {
            ret = max(ret, tmp);
            tmp=1;
        }
    }
    ret = max(ret, tmp);
    cout << ret;
}