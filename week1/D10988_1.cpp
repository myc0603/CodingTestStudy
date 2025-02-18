#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string init = "ewq";
    // cin >> init;
    string fin = init;
    int size = init.size();
    for (int i = 0; i < size; i++) {
        fin[i] = init[size-i-1];
    }

    if (init.compare(fin) == 0) {
        cout << 1;
    } else {
        cout << 0;
    }
    // cout << init.compare(fin) + 1;
}