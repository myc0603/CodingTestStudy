#include <bits/stdc++.h>
using namespace std;

int n, m, wallInfos[53][53], visited[53][53];
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};
vector<pair<int, int>> widthWalls, heightWalls;

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

bool canGo(int y, int x, int direction) {
    return !(wallInfos[y][x] & (1 << direction));
}

int dfs(int y, int x) {
    visited[y][x] = 1;

    int area = 1;

    for (int direction = 0; direction < 4; direction++) {
        int ny = y + dy[direction];
        int nx = x + dx[direction];
        if (inMap(ny, nx) && canGo(y, x, direction) && !visited[ny][nx]) {
            area += dfs(ny, nx);
        }
    }
    return area;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int wallInfo; cin >> wallInfo;
            wallInfos[i][j] = wallInfo;
            if (wallInfo & 4) {
                heightWalls.push_back({i, j});
            }
            if (wallInfo & 8) {
                widthWalls.push_back({i, j});
            }
        }
    }

    int cnt = 0;
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                maxArea = max(dfs(i, j), maxArea);
                cnt++;
            }
        }
    }

    int ans = 0;
    for (auto wall : heightWalls) {
        int y, x; tie(y, x) = wall;
        wallInfos[y][x] &= ~4;
        wallInfos[y][x+1] &= ~1;
        
        memset(visited, 0, sizeof(visited));
        ans = max(dfs(y, x), ans);

        wallInfos[y][x] |= 4;
        wallInfos[y][x+1] |= 1;
    }
    for (auto wall : widthWalls) {
        int y, x; tie(y, x) = wall;
        wallInfos[y][x] &= ~8;
        wallInfos[y+1][x] &= ~2;

        memset(visited, 0, sizeof(visited));
        ans = max(dfs(y, x), ans);

        wallInfos[y][x] |= 8;
        wallInfos[y+1][x] |= 2;
    }

    cout << cnt << '\n';
    cout << maxArea << '\n';
    cout << ans << '\n';
}