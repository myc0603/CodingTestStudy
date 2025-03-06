#include <bits/stdc++.h>
using namespace std;

#define y1 asdf

int n, m, visited1[300][300], visited2[300][300], y1, x1, y2, x2;
char a[300][300];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void bfs(int sy, int sx) {

    queue<pair<int, int>> q1;
    q1.push({sy, sx});
    visited1[sy][sx] = 1;

    queue<pair<int, int>> q2;
    q2.push({sy, sx});
    visited2[sy][sx] = 1;

    while (q1.size()) {
        int y, x;
        tie(y, x) = q1.front(); q1.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!inMap(ny, nx) || visited1[ny][nx]) continue;
            if (a[ny][nx] == '0') {
                q1.push({ny, nx});
                visited1[ny][nx] = visited1[y][x] + 1;
            } else if (a[ny][nx] == '1') {
                int y2, x2;
                tie(y2, x2) = q2.front(); q2.pop();
                q2.push({ny, nx});
                visited2[ny][nx] = visited2[y2][x2] + 1;
            }
        }
    }

    
}

int main() {
    cin >> n >> m;
    cin >> y1 >> x1 >> y2 >> x2;
    y1--; x1--; y2--; x2--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    bfs(y1, x1);
    cout << visited2[y2][x2] << '\n';
}