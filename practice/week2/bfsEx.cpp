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

// visited update => just after pushing to queue
// visited == 0 : queue에 들어간적 없음
// visited == k : 시작지점으로부터 k만큼 왔음
void bfs() {
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = 1;
    while (q.size()) {
        // tie(y, x) = q.front();
        pair<int, int> cur = q.front();
        int y = cur.first;
        int x = cur.second;
        cout << "cur point y: " << y << ", x: " << x << '\n';
        // if (cur == market) {
        //     cout << visited[y][x] << '\n';
        // }
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
    cin >> market.first >> market.second;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // print a
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }

    bfs(); // 여기서 visited[][]을 초기화했으니 이 함수 종료되고
    // 여기 밖에서 visited[market.first][market.second] 출력하면 됨
    cout << visited[market.first][market.second] << '\n';

    // print visited
    cout << "======\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << visited[i][j];
        }
        cout << '\n';
    }
    cout << "======\n";

    return 0;
}