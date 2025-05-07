#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a[10], used[10];
vector<int> v;

void combi() {
    if (v.size() == m) {
        for (int x : v) cout << x << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        v.push_back(a[i]);
        used[i] = 1;
        combi();
        v.pop_back();
        used[i] = 0;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);

    combi();
}