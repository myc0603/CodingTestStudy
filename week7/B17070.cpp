#include <iostream>
using namespace std;

int n, a[17][17], dp[17][17][3];
int dy[] = {0, 1, 1};
int dx[] = {1, 0, 1};

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}

int dfs(int y, int x, int curDir) {
    if (y == n - 1 && x == n - 1) {
        return 1;
    }

    int &result = dp[y][x][curDir];
    if (result != -1) return result;

    result = 0;
    for (int i = 0; i < 3; i++) {
        if (curDir == 0 && i == 1) continue;
        if (curDir == 1 && i == 0) continue;

        int ny = y + dy[i];
        int nx = x + dx[i];

        if (!inMap(ny, nx)) continue;
        if (a[ny][nx] == 1) continue;
        if (i == 2) {
            if (a[ny][x] == 1) continue;
            if (a[y][nx] == 1) continue;
        }
        result += dfs(ny, nx, i);
    }
    return result;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    fill(&dp[0][0][0], &dp[0][0][0] + 17 * 17 * 3, -1);
    cout << dfs(0, 1, 0);
}