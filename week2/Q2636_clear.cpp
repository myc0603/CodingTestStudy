#include <bits/stdc++.h>
using namespace std;

int n, m, a[100][100], visited[100][100];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

bool isLast() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 2) return false;
        }
    }
    return true;
}

int bfs(int step) {
    bool last  = (step == 2) && isLast();
    int cnt = 0;

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (q.size()) {
        int y, x;
        tie(y, x) = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (inMap(ny, nx) && a[ny][nx] != step && !visited[ny][nx]) {
                if (a[ny][nx] == 0) {
                    q.push({ny, nx});
                } else if (a[ny][nx] == (3-step)) {
                    a[ny][nx] = step % 2;
                    cnt++;
                }
                visited[ny][nx] = 1;
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    return last ? cnt : -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num; cin >> num;
            a[i][j] = num ? 2 : 0;
        }
    }

    int times = 0;
    int cnt = -1;
    while (cnt == -1) {
        bfs(1);
        cnt = bfs(2);
        times++;
    }

    cout << times << '\n';
    cout << cnt << '\n';
}