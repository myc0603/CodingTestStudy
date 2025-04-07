#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

int main() {
    int n; cin >> n;
    while (n--) {
        int l, t;
        cin >> l >> t;
        v.push_back({l, t});
    }

    sort(v.begin(), v.end());

    int r = -1;
    for (auto p : v) {
        int l, t;
        tie(l, t) = p;
        if (l > r) r = l + t;
        else r += t;
    }
    cout << r;
}