#include <iostream>
#include <cassert>
using namespace std;

int orders[100002], n, dp[100002][5][5];

int hp(int from, int to) {
    if (from == to) return 1;
    if (from == 0) return 2;
    if ((from + 1) % 4 == to % 4 || (from - 1) % 4 == to % 4) return 3;
    if (((from % 4) ^ 2) == (to % 4)) return 4;
    
    assert(0);
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true) {
        cin >> orders[n];
        if (orders[n++] == 0) break;
    }

    fill(&dp[0][0][0], &dp[0][0][0] + 100002 * 5 * 5, 1e8);
    dp[0][orders[0]][0] = 2;
    for (int i = 1; i < n - 1; ++i) {
        for (int l = 0; l <= 4; ++l) {
            for (int r = 0; r <= 4; ++r) {
                dp[i][orders[i]][r] = min(dp[i][orders[i]][r], dp[i-1][l][r] + hp(l, orders[i]));
                dp[i][l][orders[i]] = min(dp[i][l][orders[i]], dp[i-1][l][r] + hp(r, orders[i]));
            }
        }
    }
    
    int ans = 1e8;
    for (int l = 0; l <= 4; ++l) ans = min(ans, dp[n-2][l][orders[n-2]]);
    for (int r = 0; r <= 4; ++r) ans = min(ans, dp[n-2][orders[n-2]][r]);
    cout << ans;
}