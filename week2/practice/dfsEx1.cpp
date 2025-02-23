#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void dfs(vector<bool> a[], int y, int x, vector<bool> visited[]) {
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (!inMap(ny, nx)) continue;
        if (a[ny][nx] && !visited[ny][nx]) {
            dfs(a, ny, nx, visited);
        }
    }

}

int main() {
    cin >> n >> m;

    vector<bool> a[n];
    for (int i = 0; i < n; i++) {
        vector<bool> v;
        for (int j = 0; j < m; j++) {
            bool b; cin >> b;
            v.push_back(b);
        }
        a[i] = v;
    }

    vector<bool> visited[n];
    vector<bool> v;
    for (int j = 0; j < m; j++) {
        v.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        visited[i] = v;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] && !visited[i][j]) {
                dfs(a, i, j, visited);
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}