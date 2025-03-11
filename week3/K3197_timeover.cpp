#include <bits/stdc++.h>
using namespace std;

int n, m, visited[1500][1500];
char a[1500][1500];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void printLake() {
    cout << "=== print Lake ===\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
    cout << "==================\n";
}

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

bool bfs(int sy, int sx, vector<pair<int, int>> &v) {
    // cout << "call bfs(), sy: " << sy << ", sx: " << sx << '\n';;
    int swanCount = 0; // sy, sx있는 영역에 있는 백조 수
    queue<pair<int, int>> q;
    q.push({sy, sx});
    visited[sy][sx] = 1;

    while (q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();
        if (a[y][x] == 'L') {
            swanCount++;
            // cout << "find swan: " << swanCount << ", position: " << y << "," << x << '\n';
        }
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (inMap(ny, nx) && !visited[ny][nx]) {
                if (a[ny][nx] == 'X') {
                    v.push_back({ny, nx});
                } else {
                    q.push({ny, nx});
                    visited[ny][nx] = visited[y][x] + 1;
                }
            }
        }
    }

    return swanCount == 2;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // 녹이고 백조 만나는지 확인
    vector<pair<int, int>> willBeMelted;
    int days = 0;
    while (true) {
        // cout << "days: " << days << '\n';
        bool canMeet = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != 'X' && !visited[i][j]) {
                    // cout << i << ',' << j << '\n';
                    canMeet = bfs(i, j, willBeMelted) || canMeet;
                }
            }
        }

        if (canMeet) {
            break;
        }

        for (auto p : willBeMelted) {
            a[p.first][p.second] = '.';
        }

        // printLake();

        willBeMelted.clear();
        memset(&visited[0][0], 0, sizeof(visited));
        days++;
    }
    cout << days << '\n';
}