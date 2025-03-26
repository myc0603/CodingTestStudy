#include <bits/stdc++.h>
using namespace std;

int n, m, wallInfos[53][53], visited[53][53], compArea[2503];
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

bool canGo(int y, int x, int direction) {
    return !(wallInfos[y][x] & (1 << direction));
}

int dfs(int y, int x, int compIdx) {
    visited[y][x] = compIdx;

    int area = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (inMap(ny, nx) && canGo(y, x, i) && !visited[ny][nx]) {
            area += dfs(ny, nx, compIdx);
        }
    }
    return area;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> wallInfos[i][j];
        }
    }

    int cnt = 1;
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                compArea[cnt] = dfs(i, j, cnt);
                maxArea = max(compArea[cnt], maxArea);
                cnt++;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int idx = visited[i][j];
            int adjIdx1 = visited[i][j+1];
            int adjIdx2 = visited[i+1][j];
            if (idx != adjIdx1 && j + 1 < m) {
                ans = max(ans, compArea[idx] + compArea[adjIdx1]);
            }
            if (idx != adjIdx2 && i + 1 < n) {
                ans = max(ans, compArea[idx] + compArea[adjIdx2]);
            }
        }
    }

    cout << cnt - 1 << '\n';
    cout << maxArea << '\n';
    cout << ans << '\n';
}