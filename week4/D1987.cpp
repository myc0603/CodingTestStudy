#include <bits/stdc++.h>
using namespace std;

/// @brief charVisited[] -> 비트마스킹으로 대체
int n, m, charVisited;
char a[20][20];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int ans;

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void dfs(int y, int x, int cnt) {
    int charIdx = a[y][x] - 'A';
    charVisited |= (1 << charIdx);
    cnt++;

    ans = max(ans, cnt);

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (inMap(ny, nx)) {
            int newCharIdx = a[ny][nx] - 'A';
            if (charVisited & (1 << newCharIdx)) continue;
            
            dfs(ny, nx, cnt);
            charVisited &= ~(1 << newCharIdx);
        }
    }

}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0 ; j < m; j++) {
            a[i][j] = s[j];
        }
    }

    dfs(0, 0, 0);
    cout << ans << '\n';
}