#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string init = "ewq";
    // cin >> init;
    string fin = init;
    reverse(fin.begin(), fin.end());
    if (init.compare(fin) == 0) {
        cout << 1;
    } else {
        cout << 0;
    }
    // cout << init.compare(fin) + 1;
}