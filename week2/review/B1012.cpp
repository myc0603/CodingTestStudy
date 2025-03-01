#include <bits/stdc++.h>
using namespace std;

int n, m, a[50][50], visited[50][50];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void dfs(int y, int x) {
    visited[y][x] = 1;
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (inMap(ny, nx) && a[ny][nx] && !visited[ny][nx]) {
            dfs(ny, nx);
        }
    }
}

int main() {
    int t; cin >> t;

    vector<int> ans;

    while (t--) {
        // init
        cin >> m >> n;
        int k; cin >> k;
        while (k--) {
            int y, x;
            cin >> x >> y;
            a[y][x] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] && !visited[i][j]) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        ans.push_back(cnt);

        // rollback a, visited
        memset(a, 0, sizeof(a));
        memset(visited, 0, sizeof(visited));
    }

    for (int num : ans) {
        cout << num << '\n';
    }
}