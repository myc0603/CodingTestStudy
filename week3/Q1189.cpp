#include <bits/stdc++.h>
using namespace std;

int n, m, a[5][5], visited[5][5];
int casesCnt;
int ans;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void dfs(int y, int x, int cnt) {
    cnt++;
    visited[y][x] = 1;

    // 도착지점 0, m-1
    if (y == 0 && x == m - 1 && cnt == casesCnt) {
        ans++;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (inMap(ny, nx) && a[ny][nx] && !visited[ny][nx]) {
            dfs(ny, nx, cnt);
            visited[ny][nx] = 0;
        }
    }
}

int main() {
    cin >> n >> m >> casesCnt;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] == '.' ? 1 : 0;
        }
    }

    // 출발지점 n-1, 0
    dfs(n - 1, 0, 0);

    cout << ans << '\n';
}