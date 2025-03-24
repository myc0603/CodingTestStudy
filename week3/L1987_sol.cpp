#include <bits/stdc++.h>
using namespace std;

int n, m, charVisited[26], ans;
char a[20][20];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void dfs(int y, int x, int cnt) {
    int curAlphaIdx = a[y][x] - 'A';
    charVisited[curAlphaIdx] = 1;
    cnt++;

    ans = max(ans, cnt);

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        int newAlphaIdx = a[ny][nx] - 'A';
        if (inMap(ny, nx) && !charVisited[newAlphaIdx]) {
            dfs(ny, nx, cnt);
            charVisited[newAlphaIdx] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }

    int cnt = 0;
    dfs(0, 0, 0);

    cout << ans << '\n';
}