#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v) {
    for (int i : v) {
        cout << i << ' ';
    }
    cout << '\n';
}
int main() {
    vector<int> b = {1, 2, 3, 4, 5};
    int n = b.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                cout << i << ' ' << j << ' ' << k << '\n';
            }
        }
    }
    cout << "=======\n";
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                cout << i << ' ' << j << ' ' << k << '\n';
            }
        }
    }
    return 0;
}