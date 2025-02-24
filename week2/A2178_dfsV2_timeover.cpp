#include <bits/stdc++.h>
using namespace std;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int n, m;
vector<int> counts;
bool inMap(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

int go(vector<bool> a[], int y, int x, vector<bool> visited[], int cnt) {
    if (visited[y][x]) {
        return -1;
    }
    visited[y][x] = true;
    cnt++;
    if (y == n-1 && x == m-1) {
        counts.push_back(cnt);
        return 1;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (inMap(ny, nx) && a[ny][nx]) {
            int result = go(a, ny, nx, visited, cnt);
            if (result == 1) {
                visited[ny][nx] = false;
            }
        }
    }
    return 1;
}

int main() {
    cin >> n >> m;
    vector<bool> a[n];
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        vector<bool> v;
        for (char c : s) {
            v.push_back(c-'0');
        }
        a[i] = v;
    }

    vector<bool> visited[n];
    for (int i = 0; i < n; i++) {
        vector<bool> v;
        for (int j = 0; j < m; j++) {
            v.push_back(false);
        }
        visited[i] = v;
    }
    int cnt = 0;
    go(a, 0, 0, visited, cnt);
    int min = *min_element(counts.begin(), counts.end());
    cout << min << '\n';
}