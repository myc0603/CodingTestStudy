#include <bits/stdc++.h>
using namespace std;

int n, a[100][100], visited[100][100];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}

void dfs(int y, int x, int rain) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (inMap(ny, nx) && a[ny][nx] > rain && !visited[ny][nx]) {
            dfs(ny, nx, rain);
        }
    }
}

int main() {
    cin >> n;
    int maxHeight = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            maxHeight = max(maxHeight, a[i][j]);
        }
    }

    // rain = maxHeight일 때 안전영역은 무조건 0
    // rain = 0일 때의 안전영역은 무조건 1 -> rain = maxHeight일 때는 확인할 필요X
    int maxCnt = 0;
    for (int rain = 0; rain < maxHeight; rain++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] > rain && !visited[i][j]) {
                    dfs(i, j, rain);
                    cnt++;
                }
            }
        }
        maxCnt = max(maxCnt, cnt);
        cnt = 0;

        // rollback visited
        memset(visited, 0, sizeof(visited));
    }

    cout << maxCnt << '\n';
}