#include <bits/stdc++.h>
using namespace std;

int n, m, a[100][100], visited[100][100];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void printA() {
    cout << "=== print a[][] ===\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "===================\n";
}

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

int dfs(int y, int x) {
    visited[y][x] = 1;

    int area = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (inMap(ny, nx) && a[ny][nx] && !visited[ny][nx]) {
            area += dfs(ny, nx);
        }
    }

    return area;
}

int bfs(int y, int x) {
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push({y, x});

    int area = 0;
    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        area++;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (inMap(ny, nx) && a[ny][nx] && !visited[ny][nx]) {
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }
    
    return area;
}

int main() {
    int k;
    cin >> n >> m >> k;

    fill(&a[0][0], &a[0][0] + 100*100, 1);
    // printA();
    while (k--) {
        int y1, x1, y2, x2;
        cin >> x1 >> y1 >> x2 >> y2;

        // init a[][]
        for (int i = y1; i < y2; i++) {
            for (int j = x1; j < x2; j++) {
                a[i][j] = 0;
            }
        }
        // printA();
    }

    // area = dfs()
    vector<int> areas;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] && !visited[i][j]) {
                // areas.push_back(dfs(i, j));
                areas.push_back(bfs(i, j));
            }
        }
    }

    cout << areas.size() << '\n';
    sort(areas.begin(), areas.end());
    for (int area : areas) {
        cout << area << ' ';
    }
}