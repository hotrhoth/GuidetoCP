#include <iostream>
using namespace std;

const int N = 1000;

int main() {
    int array[] = {6, 2, 5, 1, 7, 4, 8, 3};
    int length[N] = {0};

    for(int k=0; k<8; k++) {
        length[k] = 1;
        for(int i=0; i<k; i++) {
            if(array[i] < array[k])
                length[k] = max(length[k], length[i] + 1);
        }
    }
    cout << length[8] << "\n";
}