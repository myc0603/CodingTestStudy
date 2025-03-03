#include <bits/stdc++.h>
using namespace std;

int n, m, a[50][50], visited[50][50];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void printVisited() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

int bfs(int y, int x) {
    int dis = 0;
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;

    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        // q.size() == 1일 때만 해도 될 거 같기도?
        dis = max(dis, visited[y][x]);

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (inMap(ny, nx) && a[ny][nx] && !visited[ny][nx]) {
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
    }


    return dis - 1; // 자기 칸 제외
}

int main() {
    // visited 초기화 조심
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] == 'L';
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]) {
                int temp = bfs(i, j);
                cout << "(i,j): (" << i << ',' << j << ")  bfs(i,j): " << temp << '\n';
                cout << "visited\n";
                printVisited();
                ans = max(ans, temp);
                //init visited
                memset(visited, 0, sizeof(visited));
            }
        }
    }

    cout << ans << '\n';
}