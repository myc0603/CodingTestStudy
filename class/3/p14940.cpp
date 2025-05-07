#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

int n, m, a[1005][1005], visited[1005][1005];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void bfs(int sy, int sx) {
    queue<pair<int, int>> q;
    q.push( {sy, sx} );
    visited[sy][sx] = 0;

    while (q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (visited[ny][nx] != -1) continue;
            if (inMap(ny, nx) && a[ny][nx]) {
                q.push( {ny, nx} );
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    vector<pair<int, int>> cannotGo;
    int sy, sx;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                sy = i; sx = j;
            } else if (a[i][j] == 0) {
                cannotGo.push_back( {i, j} );
            }
        }
    }

    fill(visited[0], visited[0] + 1005 * 1005, -1);
    bfs(sy, sx);
    for (auto p : cannotGo) {
        visited[p.first][p.second] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
}