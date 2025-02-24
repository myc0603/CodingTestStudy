#include <bits/stdc++.h>
using namespace std;

int a[50][50], visited[50][50];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int n, m;

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (inMap(ny, nx) && a[ny][nx] && !visited[ny][nx]) {
            dfs(ny, nx);
        }
    }
}

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (inMap(ny, nx) && a[ny][nx] && !visited[ny][nx]) {
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int l;
        cin >> m >> n >> l;
        while (l--) {
            int x, y;
            cin >> x >> y;
            a[y][x] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] && !visited[i][j]) {
                    // dfs(i, j);
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
        memset(a, 0, sizeof(a));
        memset(visited, 0, sizeof(visited));
    }
}