#include <iostream>
#include <algorithm>
using namespace std;

int n, m, l, pos[53];

bool ok(int d) {
    int cnt = 0;
    for (int i = 1; i <= n + 1; ++i) {
        cnt += (pos[i] - pos[i-1] - 1) / d;
        if (cnt > m) return false;
    }
    return true;
}

int main() {
    cin >> n >> m >> l;
    pos[0] = 0;
    for (int i = 1; i <= n; ++i) cin >> pos[i];
    pos[n+1] = l;
    sort(pos, pos + n + 2);

    int left = 0, r = l + 1;
    while (left + 1 < r) {
        int mid = (left + r) / 2;
        if (ok(mid)) r = mid;
        else left = mid;
    }
    cout << r;
}