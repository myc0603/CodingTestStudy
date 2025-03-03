#include <bits/stdc++.h>
using namespace std;

int n, l, r, a[50][50], visited[50][50];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}

bool willMove(int p1, int p2) {
    return l <= abs(p1 - p2) && abs(p1 - p2) <= r;
}

void dfs(int y, int x, vector<pair<int, int>> &united) {
    visited[y][x] = 1;
    united.push_back({y, x});

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (inMap(ny, nx) && willMove(a[y][x], a[ny][nx]) && !visited[ny][nx]) {
            dfs(ny, nx, united);
        }
    }
}

bool share(const vector<pair<int, int>> &united) {
    if (united.size() == 1) {
        return false;
    }

    int tot = 0;
    for (auto p : united) {
        tot += a[p.first][p.second];
    }
    int newNum = tot / united.size();
    for (auto p : united) {
        a[p.first][p.second] = newNum;
    }

    return united.size() > 1;
}

int main() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int days = 0;
    for (bool moved = true; moved; days++) {
        moved = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    vector<pair<int, int>> united;
                    dfs(i, j, united);
                    moved = share(united) || moved;
                }
            }
        }

        memset(visited, 0, sizeof(visited));
    }
    cout << days - 1 << '\n';
}