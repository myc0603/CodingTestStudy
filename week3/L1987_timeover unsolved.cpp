#include <bits/stdc++.h>
using namespace std;

int n, m, visited[20][20];
char a[20][20];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
set<char> st;
vector<int> ans;

bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void dfs(int y, int x, int cnt) {
    visited[y][x] = 1;
    st.insert(a[y][x]);
    cnt++;

    bool canGo = false;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (inMap(ny, nx) && !visited[ny][nx] && st.find(a[ny][nx]) == st.end()) {
            // cout << y << ',' << x << " -> " << ny << ',' << nx << '\n';
            // cout << a[y][x] << " -> " << a[ny][nx] << '\n';
            dfs(ny, nx, cnt);
            visited[ny][nx] = 0;
            st.erase(a[ny][nx]);
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