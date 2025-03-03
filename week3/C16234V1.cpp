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

vector<pair<int, int>> bfs(int sy, int sx) {

    vector<pair<int, int>> united;

    queue<pair<int, int>> q;
    q.push({sy, sx});
    visited[sy][sx] = 1;

    while (q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();
        united.push_back({y, x});

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (inMap(ny, nx) && willMove(a[y][x], a[ny][nx]) && !visited[ny][nx]) {
                q.push({ny, nx});
                visited[ny][nx] = 1;
            }
        }
    }

    return united;
}

bool share(const vector<pair<int, int>> &united) {
    if (united.size() == 1) {
        return false;
    }

    int tot = 0;
    for (auto country : united) {
        tot += a[country.first][country.second];
    }
    int newPopulation = tot / united.size();
    for (auto country : united) {
        a[country.first][country.second] = newPopulation;
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
    for (bool moved = true; moved;) {
        // cout << "day" << days + 1 << '\n';
        moved = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    vector<pair<int, int>> united = bfs(i, j);
                    // 매 days마다 인구이동된 결과를 출력해서 확인
                    // 확인해봤는데 share()가 왜 어디가 실행이 안됨
                    // moved = moved || share(united);
                    moved = share(united) || moved;
                }
            }
        }
        if (moved) {
            days++;
        }
        // moved ? cout << "people moved\n\n" : cout << "people not moved\n\n";

        memset(visited, 0, sizeof(visited));
    }
    cout << days << '\n';
}