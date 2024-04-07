#include <iostream>
#include <vector>
using namespace std;

// 8 2 4 6 8 1 3 5 7
int main() {
    int n; cin >> n;
    vector <int> children(n);
    for(int i=0; i<n; i++) children[i] = i+1;
    while(children.size()>1) {
        vector <int> survivor;
        for(int i=0; i<children.size(); i++) {
            if((i&1)) cout << children[i] << " ";
            else survivor.push_back(children[i]);
        }
        if(children.size()%2==0) children = survivor;
        else {
            int tmp = survivor.back();
            survivor.pop_back();
            children.clear();
            children.push_back(tmp);
            for(auto x: survivor) children.push_back(x);
       }
    }
    cout << children[0];
    

}