#include <bits/stdc++.h>
using namespace std;

int n, m, a[100][100], visited[100][100];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

// Flood Fill
pair<int, int> bfs() {
    queue<pair<int, int>> q; // 0이 들어가는 큐
    q.push({0, 0});
    visited[0][0] = 1;

    int times = 0;
    int cnt;
    while (q.size()) {
        queue<pair<int, int>> temp; // 1이 들어가는 큐
        times++;
        cnt = 0;
        while (q.size()) { // 0은 쫘악 탐색하고 1은 temp에 담아놨다가 1부터 시작해서 스텝에서 쫘악 탐색
            int y, x;
            tie(y, x) = q.front(); q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (!inMap(ny, nx) || visited[ny][nx]) continue;
                if (a[ny][nx] == 0) {
                    q.push({ny, nx});
                } else {
                    temp.push({ny, nx});
                    a[ny][nx] = 0;
                    cnt++;
                }
                visited[ny][nx] = 1;
            }
        }
        q = temp; // q에 1위치를 담는다.
    }

    return {times, cnt};
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    pair<int, int> ans = bfs();
    cout << ans.first << '\n' << ans.second;
}