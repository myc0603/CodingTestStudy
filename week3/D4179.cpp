#include <bits/stdc++.h>
using namespace std;

int n, m, a[1000][1000], visited[1000][1000], fireVisited[1000][1000];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void fireBfs(int sy, int sx) {
    queue<pair<int, int>> q;
    q.push({sy, sx});
    fireVisited[sy][sx] = 1;

    while (q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!inMap(ny, nx) || !a[ny][nx]) {
                continue;
            }
            if (!fireVisited[ny][nx] || fireVisited[y][x] + 1 < fireVisited[ny][nx]) {
                q.push({ny, nx});
                fireVisited[ny][nx] = fireVisited[y][x] + 1;
            }
        }
    }

}

int bfs(int sy, int sx) {
    queue<pair<int, int>> q;
    q.push({sy, sx});
    visited[sy][sx] = 1;

    while (q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!inMap(ny, nx)) {
                // escape!!
                return visited[y][x];
            }
            if (!a[ny][nx] || visited[ny][nx]) {
                continue;
            }
            if (!fireVisited[ny][nx] || visited[y][x] + 1 < fireVisited[ny][nx]) {
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
    }
    // 탈출 실패
    return -1;
}

int main() {
    cin >> n >> m;
    vector<pair<int, int>> fires;
    pair<int, int> jihoonPos;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] == '#' ? 0 : 1;
            if (s[j] == 'F') {
                fires.push_back({i, j});
            }
            if (s[j] == 'J') {
                jihoonPos = {i, j};
            }
        }
    }

    cout << "print a\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    for (auto fire : fires) {
        fireBfs(fire.first, fire.second);
    }

    cout << "print fireVisited\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << fireVisited[i][j] << ' ';
        }
        cout << '\n';
    }

    int ans = bfs(jihoonPos.first, jihoonPos.second);

    cout << "print visited\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }

    if (ans == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << ans << '\n';
    }
}