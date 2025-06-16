#include <iostream>
using namespace std;

int n, a[18][18], dp[18][18][3];

void update(int y, int x) {
    if (a[y][x] == 0) {
        dp[y][x][0] += dp[y][x-1][0] + dp[y][x-1][1];
        dp[y][x][2] += dp[y-1][x][1] + dp[y-1][x][2];
    }
    if (a[y][x] == 0 && a[y][x-1] == 0 && a[y-1][x] == 0) {
        dp[y][x][1] += dp[y-1][x-1][0] + dp[y-1][x-1][1] + dp[y-1][x-1][2];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    dp[1][2][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            update(i, j);
        }
    }

    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
}