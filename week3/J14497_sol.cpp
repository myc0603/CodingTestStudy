#include <bits/stdc++.h>
using namespace std;

int n, m, visited[300][300];
char a[300][300];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

int main() {
    int y1, x1, y2, x2;
    cin >> n >> m >> y1 >> x1 >> y2 >> x2;
    y1--; x1--; y2--; x2--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({y1, x1});
    visited[y1][x1] = 1;

    int cnt = 1;
    bool find = false;
    // while (a[y2][x2] != '0') {
    // while (!find) {
    while (true) {
        queue<pair<int, int>> temp;
        while (q.size()) {
            int y, x;
            tie(y, x) = q.front(); q.pop();

            // if (y == y2 && x == x2) {
            //     find = true;
            //     break;
            // }

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (inMap(ny, nx) && !visited[ny][nx]) {
                    visited[ny][nx] = 1;
                    if (a[ny][nx] == '#') {
                        cout << cnt << '\n';
                        return 0;
                    }
                    if (a[ny][nx] == '0') {
                        q.push({ny, nx});
                    } else {
                        // a[ny][nx] = '0'; // 1을 0으로 바꿔줄 필요는 없는듯
                        temp.push({ny, nx});
                    }
                }
            }
        }
        q = temp;
        // temp에 저장된 위치 값들을 0으로 바꿔줘야 되나?
        cnt++;
    }
    // cout << cnt << '\n';
}