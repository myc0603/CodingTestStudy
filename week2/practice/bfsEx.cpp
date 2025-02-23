#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100][100], visited[100][100];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

pair<int, int> start, market;

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void bfs() {
    queue<pair<int, int>> q;
    q.push(start);

    while (q.size()) {

        pair<int, int> cur = q.front();
        int y = cur.first;
        int x = cur.second;
        if (cur == market) {
            cout << visited[y][x] << '\n';
        }
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if (inMap(ny, nx) && a[ny][nx] && visited[ny][nx] == 0) {
                q.push(make_pair(ny, nx));
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    cin >> start.first >> start.second;
    cin >> market.first >> market.first;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    bfs();

    return 0;
}