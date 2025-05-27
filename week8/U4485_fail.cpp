#include <iostream>
using namespace std;

int n, a[127][127], dp[127][127][4];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int dfs(int i, int j, int dir) {
    if (i >= n || j >= n || i < 0 || j < 0) return 1e9;
    if (i == n - 1 && j == n - 1) return a[i][j];

    int &result = dp[i][j][dir];
    if (result != -1) return result;

    result = 1e9;
    for (int k = 0; k < 4; ++k) {
        if (k == (dir ^ 1)) continue;
        int ni = i + dy[k];
        int nj = j + dx[k];
        result = min(result, dfs(ni, nj, k));
    }
    result += a[i][j];
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i = 1;
    while (true) {
        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        fill(&dp[0][0][0], &dp[0][0][0] + 127 * 127 * 4, -1);
        
        cout << "Problem " << i++ << ": " << min(dfs(0, 0, 0), dfs(0, 0, 2)) << '\n';

        cout << "check dp\n";
        // for (int i = 0; i < n;)
    }
}