#include <bits/stdc++.h>
using namespace std;

int n, m, wallInfos[53][53], visited[53][53];
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};
vector<pair<int, int>> widthWalls, heightWalls;

void printWallInfos() {
    cout << "print WallInfos\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << wallInfos[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

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
            if (wallInfo & 4) { // 오른쪽 세로 벽
                heightWalls.push_back({i, j});
            }
            if (wallInfo & 8) { // 아래쪽 가로 벽
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

    // 벽을 하나씩 없애봐야됨..
    int ans = 0;
    for (auto wall : heightWalls) {
        // 벽 제거
        int y = wall.first;
        int x = wall.second;
        wallInfos[y][x] &= ~4;
        wallInfos[y][x+1] &= ~1;
        
        // cout << "after remove wall at " << y << ',' << x << '\n';
        // printWallInfos();

        // 방 최대 넓이 구해보고
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    ans = max(dfs(i, j), ans);
                }
            }
        }

        // 제거한 벽 원상복구
        wallInfos[y][x] |= 4;
        wallInfos[y][x+1] |= 1;
    }
    for (auto wall : widthWalls) {
        int y = wall.first;
        int x = wall.second;
        wallInfos[y][x] &= ~8;
        wallInfos[y+1][x] &= ~2;

        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    ans = max(dfs(i, j), ans);
                }
            }
        }

        wallInfos[y][x] |= 8;
        wallInfos[y+1][x] |= 2;
    }

    cout << cnt << '\n';
    cout << maxArea << '\n';
    cout << ans << '\n';
}