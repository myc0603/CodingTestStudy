#include <iostream>
using namespace std;

int n, cost[1000][3], dp[3][1000][3];

int dfs(int firstColor, int idx, int prevColor) {
    int &result = dp[firstColor][idx][prevColor];
    if (result) return result;

    if (idx == n - 1) {
        int cand = (firstColor + 1) % 3;
        if (cand == prevColor) {
            result = cost[n-1][(cand + 1) % 3];
        } else {
            result = cost[n-1][cand];
            if ((cand + 1) % 3 != prevColor) result = min(result, cost[n-1][(cand + 1) % 3]);
        }
        return result;
    }

    int curColor1 = (prevColor + 1) % 3;
    int curColor2 = (prevColor + 2) % 3;
    result = min(dfs(firstColor, idx + 1, curColor1) + cost[idx][curColor1],
                    dfs(firstColor, idx + 1, curColor2) + cost[idx][curColor2]);
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