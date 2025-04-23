#include <iostream>
#include <queue>
using namespace std;

int n, m, a[1005][1005], visited[1005][1005];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void printA() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool allRipen() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) return false;
        }
    }
    return true;
}

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

int bfs(queue<pair<int, int>> &q) {
    int days = 0;

    while (q.size()) {
        int qsize = q.size();

        for (int i = 0; i < qsize; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            a[y][x] = 1;

            for (int j = 0; j < 4; j++) {
                int ny = y + dy[j];
                int nx = x + dx[j];
                if (inMap(ny, nx) && !visited[ny][nx] && a[ny][nx] == 0) {
                    q.push( {ny, nx} );
                    visited[ny][nx] = 1;

                }
            }
        }

        days++;
    }

    return days - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                q.push( {i, j} );
                // visited[i][j] = 1;
            }
        }
    }

    int result = bfs(q);

    printA();

    if (allRipen()) cout << result;
    else cout << -1;
}