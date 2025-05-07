#include <iostream>
using namespace std;

int n, cost[1000][3], dp[3][1002][3];

int dfs(int firstColor, int idx, int prevColor) {
    int &result = dp[firstColor][idx][prevColor];
    if (result) return result;

    result = 1e9;
    if (idx == n - 1) {
        for (int color = 0; color < 3; ++color) {
            if (color == firstColor || color == prevColor) continue;
            result = min(result, cost[n-1][color]);
        }
        return result;
    }

    for (int c = 0; c < 3; ++c) {
        if (c == prevColor) continue;
        result = min(result, dfs(firstColor, idx + 1, c) + cost[idx][c]);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    cout << min(min(dfs(0, 1, 0) + cost[0][0], dfs(1, 1, 1) + cost[0][1]), dfs(2, 1, 2) + cost[0][2]);
}