#include <iostream>
using namespace std;

const int INF = 1e9;
int n, a[17][17], dp[17][1 << 16];

int dfs(int idx, int visited) {
    if (visited == ((1 << n) - 1)) return a[idx][0];
    
    int &result = dp[idx][visited];
    if (result != -1) return result;

    result = INF;
    for (int i = 0; i < n; ++i) {
        if (i == idx || a[idx][i] == INF || (visited & (1 << i))) continue;
        result = min(result, dfs(i, visited | (1 << i)) + a[idx][i]);
    }
    return result;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 0) a[i][j] = INF;
        }
    }

    fill(&dp[0][0], &dp[0][0] + 17 * (1 << 16), -1);
    cout << dfs(0, 1);
}