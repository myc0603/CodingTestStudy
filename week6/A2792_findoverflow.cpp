#include <iostream>
using namespace std;
int n, m, color_cnt[300005];
bool check(int max_cnt) {
    long long x = 0;
    // int x = 0;
    for (int i = 0; i < m; i++) {
        x += (color_cnt[i] + max_cnt - 1) / max_cnt;
    }

    // overflow when n = 2e9;
    if (max_cnt == 122070) {
        cout << "\ncheck(" << max_cnt << ") = " << x << " -> result: " << (x <= n ? "true" : "false") << "\n";
    }

    return x <= n;
}

void init_cond() {
    n = 2e9;
    // n = 1e9; // n >= m
    m = 300000; // 30만
    for (int i = 0; i < m; i++) {
        color_cnt[i] = 2e9;
        // color_cnt[i] = 1e9;
    }
}

int main() {
    init_cond();
    int left = 0, right = 1e9;
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        // cout << "left : " << left << ", mid: " << mid << ", right: " << right;
        if (check(mid)) {
            // cout << " -> check(mid) is true, right: " << right << " -> " << mid << '\n';
            right = mid;
        } else {
            // cout << " -> check(mid) is false, left: " << left << " -> " << mid << '\n';
            left = mid;
        }
    }
    // 1은 나오면 안될거 같은데데
    cout << right;
}