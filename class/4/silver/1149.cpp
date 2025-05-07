#include <iostream>
using namespace std;

int n, cost[1002][3], dp[1002][3];

int dfs(int idx, int prevColor) {
    if (idx == n) return 0;

    int &result = dp[idx][prevColor];
    if (result) return result;

    result = 1e9;
    for (int c = 0; c < 3; ++c) {
        if (c == prevColor) continue;
        result = min(result, dfs(idx + 1, c) + cost[idx][c]);
    }
    return result;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

    cout << min(min(dfs(1, 0) + cost[0][0], dfs(1, 1) + cost[0][1]), dfs(1, 2) + cost[0][2]);
}