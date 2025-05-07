#include <iostream>
#include <vector>
// #include <set>
#include <algorithm>
using namespace std;

int n, m, a[10], used[10];
vector<int> v;
// set<vector<int>> ans;

void combi() {
    if (v.size() == m) {
        for (int x : v) cout << x << ' ';
        cout << '\n';
        return;
    }

    int prev = -1;
    for (int i = 0; i < n; ++i) {
        // if (used[i]) continue;
        if (used[i] || prev == a[i]) continue;
        used[i] = 1;
        v.push_back(a[i]);
        combi();
        v.pop_back();
        used[i] = 0;

        prev = a[i];
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    combi();

    // for (auto vec : ans) {
    //     for (int x : vec) cout << x << ' ';
    //     cout << '\n';
    // }
}