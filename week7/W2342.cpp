#include <iostream>
#include <vector>
#include <cstring>
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

int dfs(int idx, int l, int r) {
    if (idx == n - 1) return 0;

    int &result = dp[idx][l][r];
    if (result != -1) return result;

    result = min(dfs(idx + 1, orders[idx], r) + hp(l, orders[idx]),
                    dfs(idx + 1, l, orders[idx]) + hp(r, orders[idx])
    );
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (true) {
        cin >> orders[n];
        if (orders[n++] == 0) break;
    }

    memset(dp, -1, sizeof(dp));
    cout << 2 + dfs(1, orders[0], 0);
}