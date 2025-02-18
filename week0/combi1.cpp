#include <bits/stdc++.h>
using namespace std;

int n = 5, r = 3, a[5] = {1, 2, 3, 4, 5};
void print(vector<int> v) {
    for (int i : v) {
        cout << i << ' ';
    }
    cout << '\n';
}
void combi(int start, vector<int> &to) {
    if (to.size() == r) {
        print(to);
        return;
    }

    for (int i = start + 1; i < n; i++) {
        to.push_back(a[i]);
        combi(i, to);
        to.pop_back();
    }
}
int main() {
    vector<int> to = {};
    combi(-1, to);
    return 0;
}