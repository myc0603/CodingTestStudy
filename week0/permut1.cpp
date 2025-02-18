#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v);

int main() {
    vector<int> v = {1, 2, 3};
    do {
        printVec(v);
    } while (next_permutation(v.begin(), v.end()));

    int a[] = {1, 2, 3};
    cout << '\n';
    do {
        for (int i : a) {
            cout << i << ' ';
        }
        cout << '\n';
    } while (next_permutation(a, a+3));
    
    return 0;
}

void printVec(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}