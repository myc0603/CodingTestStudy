#include <bits/stdc++.h>
using namespace std;

int n, m, a[300][300], visited[300][300];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

bool bfs(int sy, int sx, vector<pair<int, int>> &v) {

    queue<pair<int, int>> q;
    q.push({sy, sx});
    visited[sy][sx] = 1;

    while (q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (!inMap(ny, nx) || visited[ny][nx]) continue;
            if (a[ny][nx] == 0) {
                q.push({ny, nx});
                visited[ny][nx] = 1;
            } else if (a[ny][nx] == 1) {
                v.push_back({ny, nx});
            } else if (a[ny][nx] == 2) { // find!!
                return true;
            }
        }
    }

    return false;
}

bool dfs(int y, int x, vector<pair<int, int>> &v) {
    bool result = false;
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (!inMap(ny, nx) || visited[ny][nx]) continue;
        if (a[ny][nx] == 0) {
            // visited[ny][nx] = 1;
            result = dfs(ny, nx, v) || result;
        } else if (a[ny][nx] == 1) {
            v.push_back({ny, nx});
        } else if (a[ny][nx] == 2) { // find!!
            return true;
        }
    }

    return result;
}

int main() {
    cin >> n >> m;
    int x1, y1, x2, y2;
    cin >> y1 >> x1 >> y2 >> x2;
    y1--; x1--; y2--; x2--;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
            if (s[j] == '#') a[i][j] = 2;
            if (s[j] == '*') a[i][j] = 0;
            
        }
    }

    int cnt = 0;
    while (true) {
        vector<pair<int, int>> v;
        // bool result = bfs(y1, x1, v);
        bool result = dfs(y1, x1, v);
        cnt++;

        if (result) {
            break;
        }

        for (auto p : v) {
            a[p.first][p.second] = 0;
        }
        memset(visited, 0, sizeof(visited));
    }

    cout << cnt << '\n';
}