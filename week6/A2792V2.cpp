#include <iostream>
#include <algorithm>
using namespace std;

int n, m, color_cnt[300005];

bool check(int max_cnt) {
    long long x = 0;
    for (int i = 0; i < m; i++) {
        x += (color_cnt[i] + max_cnt - 1) / max_cnt;
    }
    return x <= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int left = 1, right = 0;
    for (int i = 0; i < m; i++) {
        cin >> color_cnt[i];
        right = max(right, color_cnt[i]);
    }

    while (left < right) {
        int mid = (left + right) / 2;
        if (check(mid)) right = mid;
        else left = mid + 1;
    }
    cout << left;
}