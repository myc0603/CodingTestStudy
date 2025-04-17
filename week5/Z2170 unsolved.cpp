#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> a[1000004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        a[i] = {s, e};
    }

    sort(a, a + n);

    int e = -1e9;
    int len = 0;
    for (int i = 0; i < n; i++) {
        if (e >= a[i].second) continue;
        if (e > a[i].first) len += a[i].second - e;
        else len += a[i].second - a[i].first;
        e = a[i].second;
    }

    cout << len;
}