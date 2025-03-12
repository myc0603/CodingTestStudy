#include <bits/stdc++.h>
using namespace std;

int n, m, visited[20][20];
char a[20][20];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int charVisited[26];
vector<int> ans;

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void dfs(int y, int x, int cnt) {
    visited[y][x] = 1;
    int curAlphaIdx = a[y][x] - 'A';
    charVisited[curAlphaIdx] = 1;
    cnt++;

    bool canGo = false;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        int newAlphaIdx = a[ny][nx] - 'A';
        if (inMap(ny, nx) && !visited[ny][nx] && !charVisited[newAlphaIdx]) {
            // cout << y << ',' << x << " -> " << ny << ',' << nx << '\n';
            // cout << a[y][x] << " -> " << a[ny][nx] << '\n';
            dfs(ny, nx, cnt);
            visited[ny][nx] = 0;
            charVisited[newAlphaIdx] = 0;
            canGo = true;
        }
    }
    
    if (!canGo) {
        // for (char c : st) {
        //     cout << c << ' ';
        // }
        // cout << '\n';
        ans.push_back(cnt);
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

    // for (int num : ans) {
    //     cout << num << ' ';
    // }
    // cout << '\n';

    cout << *max_element(ans.begin(), ans.end()) << '\n';
}