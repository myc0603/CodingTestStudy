#include <bits/stdc++.h>
using namespace std;
void print(const vector<int> &v) {
    for (int i : v) {
        cout << i << ' ';
    }
    cout << '\n';
}
void combination(int n, int r, int start, const vector<int> &from, vector<int> &to) {
    if (r == to.size()) {
        print(to);
        return;
    }

    for (int i = start + 1; i < n; i++) {
        // for (int j = 0; j < start + 1; j++) cout << '\t';
        // printf("start for loop -> start: %d, i: %d, from[i]: %d\n", start, i, from[i]);
        to.push_back(from[i]);
        combination(n, r, i, from, to);
        to.pop_back();
        // for (int j = 0; j < start + 1; j++) cout << '\t';
        // printf("end for loop -> start: %d, i: %d, from[i]: %d\n", start, i, from[i]);
    }
}
int main() {
    vector<int> from = {1, 2, 3};
    int n = from.size();
    int r = 2;
    vector<int> to = {};
    combination(n, r, -1, from, to);

    return 0;
}