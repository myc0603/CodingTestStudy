#include <bits/stdc++.h>
using namespace std;

int n, m, a[1500][1500], visited[1500][1500];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void printA() {
    cout << "\nprintA\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) cout << '.';
            else if (a[i][j] == 2) cout << 'L';
            else cout << 'X';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

int dfs(int y, int x, vector<pair<int, int>> &v) {
    
    int cnt = 0;
    visited[y][x] = 1;
    if (a[y][x] == 2) {
        cout << "find~ y,x: " << y << ',' << x << '\n';;
        cnt++;
        cout << "cnt: " << cnt << '\n';
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (inMap(ny, nx) && !visited[ny][nx]) {
            if (a[ny][nx]) {
                cnt += dfs(ny, nx, v);
            } else {
                v.push_back({ny, nx});
            }
            // if (a[ny][nx] == 2) { // find!
            //     cnt++;
            // }
        }
    }

    return cnt;
}

int main() {
    cin >> n >> m;
    int sy, sx;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '.') a[i][j] = 1;
            else if (s[j] == 'X') a[i][j] = 0;
            else { // 백조의 위치
                a[i][j] = 2;
                sy = i; sx = j;
            }
        }
    }

    printA();

    int days = 0;
    vector<pair<int, int>> v;
    while (true) {
        
        v.clear();
        memset(visited, 0, sizeof(visited));

        // 녹일 얼음 v에 넣기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] && !visited[i][j]) {
                    int result = dfs(i, j, v);
                    if (result == 2) {
                        cout << "can meet~~!!!!" << '\n';
                        cout << days << '\n';
                        return 0;
                    }
                }
            }
        }

        // 얼음 녹이기
        for (auto p : v) {
            a[p.first][p.second] = 1;
        }
        
        printA();

        days++;
    }
}