#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int n, m, a[52][52], dp[52][52], visited[52][52];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

int dfs(int y, int x) {
    visited[y][x] = 1;

    int &result = dp[y][x];
    if (result != -2) return result;

    result = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i] * a[y][x];
        int nx = x + dx[i] * a[y][x];
        if (!inMap(ny, nx)) continue;
        if (a[ny][nx] == -1) continue;
        if (visited[ny][nx]) return INF;
        result = max(result, dfs(ny, nx) + 1);
        visited[ny][nx] = 0;
    }
    return result;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
            if (s[j] == 'H') a[i][j] = -1;
        }
    }

    fill(&dp[0][0], &dp[0][0] + 52 * 52, -2);
    int ans = dfs(0, 0);
    if (ans >= INF) cout << -1;
    else cout << ans;
}