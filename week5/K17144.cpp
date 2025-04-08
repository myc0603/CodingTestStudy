#include <bits/stdc++.h>
#define y1 asdf
using namespace std;

int n, m, a[50][50], t, y1, y2;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

bool inMap(int y, int x) {
    if (x == 0 && (y == y1 || y == y2)) return false;
    return 0 <= y && y < n && 0 <= x && x < m;
}

void diffuse() {
    vector<pair<pair<int, int>, int>> v; // position, amount of added dust
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (a[y][x] > 0) {
                // diffuse
                int dust = a[y][x];
                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (inMap(ny, nx)) {
                        v.push_back({ {ny, nx}, dust / 5});
                        a[y][x] -= dust / 5;
                    }
                }
            }
        }
    }

    for (auto p : v) {
        int y, x, addDust;
        tie(y, x) = p.first; addDust = p.second;
        a[y][x] += addDust;
    }
}

void purify() {
    for (int i = y1 - 2; i >= 0; i--) a[i+1][0] = a[i][0];
    for (int i = y2 + 2; i < n; i++) a[i-1][0] = a[i][0];

    for (int j = 1; j < m; j++) {
        a[0][j-1] = a[0][j];
        a[n-1][j-1] = a[n-1][j];
    }

    for (int i = 1; i <= y1; i++) a[i-1][m-1] = a[i][m-1];
    for (int i = n-2; i >= y2; i--) a[i+1][m-1] = a[i][m-1];

    for (int j = m - 2; j >= 1; j--) {
        a[y1][j+1] = a[y1][j];
        a[y2][j+1] = a[y2][j];
    }

    a[y1][1] = 0;
    a[y2][1] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == -1) y2 = i;
        }
    }
    y1 = y2 - 1;

    while (t--) {
        diffuse();
        purify();
    }

    int total = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            total += a[i][j];
        }
    }
    cout << total;
}