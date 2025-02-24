#include <bits/stdc++.h>
using namespace std;

int a[100][100], visited[100][100];
int n, m, area;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool inMap(int y, int x) {
    return 0 <= y & y < n && 0 <= x && x < m;
}

void dfs(int y, int x) {
    
    visited[y][x] = 1;
    area++;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (inMap(ny, nx) && a[ny][nx] && !visited[ny][nx]) {
            dfs(ny, nx);
        }
    }
}

int main() {
    int k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = 1;
        }
    }

    while (k--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1; i < y2; i++) {
            for (int j = x1; j < x2; j++) {
                a[i][j] = 0;
            }
        }
    }

    int cnt = 0;
    vector<int> areas;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] && !visited[i][j]) {
                dfs(i, j);
                areas.push_back(area);
                cnt++;
                area = 0;
            }
        }
    }
    sort(areas.begin(), areas.end());
    cout << cnt << '\n';
    for (int num : areas) {
        cout << num << ' ';
    }
}
