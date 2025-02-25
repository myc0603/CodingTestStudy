#include <bits/stdc++.h>
using namespace std;

int n, m, a[100][100], visited[100][100];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void printA() {
    cout << "========================\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "========================\n";
}

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

// 2 -> 1, step = 1
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

            // if (inMap(ny, nx) && step == 2 && a[ny][nx] == 2) {
            // if (inMap(ny, nx) && a[ny][nx] == step) {
            //     last = false;
            // }
            if (inMap(ny, nx) && a[ny][nx] != step && !visited[ny][nx]) {
                if (a[ny][nx] == 0) {
                    q.push({ny, nx});
                } else if (a[ny][nx] == (3-step)) { // 1
                    a[ny][nx] = step % 2; // step: 2, 0
                    cnt++;
                }
                visited[ny][nx] = 1;
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    // cout << "step: " << step << ", last: " << last << ", cnt: " << cnt << '\n';
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

    // printA();

    // bfs(1);
    // printA();
    // bfs(2); // 한시간 후
    // printA();

    // bfs(1);
    // printA();
    // bfs(2); // 두시간 후
    // printA();
    
    // bfs(1);
    // printA();
    // bfs(2); // 세시간 후
    // printA();

    int times = 0;
    int cnt = -1;
    while (cnt == -1) {
        bfs(1);
        cnt = bfs(2);
        times++;
        // cout << "cnt: " << cnt << '\n';
    }

    cout << times << '\n';
    cout << cnt << '\n';
}