#include <iostream>
#include <queue>
using namespace std;

// DP로 풀기~~!!

// dp배열 필요해보이긴 함.
int n, m, a[502][502], visited[502][502];
int dy[] = {1, 0, 0};
int dx[] = {0, 1, -1};
// int dy[] = {1, 0};
// int dx[] = {0, 1};

bool outOfMap(int y, int x) {
    return y < 0 || n <= y || x < 0 || m <= x;
}

int dfs(int y, int x, int count) {
    if (count == 4) return a[y][x];

    int result = 0;
    visited[y][x] = 1;
    for (int i = 0; i < 3; ++i) {
        if (i == 2 && count == 1) break;
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (outOfMap(ny, nx) || visited[ny][nx]) continue;
        result = max(result, dfs(ny, nx, count + 1) + a[y][x]);
        visited[ny][nx] = 0;
    }
    // if (result == 0 && count < 4) return -1e9;
    return result;
}

int bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push( {y, x} );
    visited[y][x] = 1;

    while (q.size()) {
         
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    // cout << dfs(0, 0, 1);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // 여기서 visited 초기화?
            // dfs(i, j, 1);
            ans = max(ans, dfs(i, j, 1));
            visited[i][j] = 0; // 차피 필요없긴 할텐디
        }
    }
    cout << ans;
}