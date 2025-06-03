#include <iostream>
#include <queue>
using namespace std;

int n, m, dp[5][510][510], dp2[5][510][510], ans;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> dp[1][i][j];
        }
    }

    // dp[2][i][j];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[2][i][j] = dp[1][i][j] + max(dp[1][i][j+1], dp[1][i+1][j]);
            dp2[2][i][j] = dp[1][i][j] + max(dp[1][i][j+1], dp[1][i-1][j]);
        }
    }

    // dp[3][i][j]
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[3][i][j] = dp[1][i][j] + max(dp[1][i][j+1] + dp[1][i+1][j], max(dp[2][i][j+1], dp[2][i+1][j]));
            dp2[3][i][j] = dp[1][i][j] + max(dp2[2][i][j+1], dp2[2][i-1][j]);
        }
    }

    // dp[4][i][j]
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int temp = max(max(dp[3][i][j+1], dp[3][i+1][j]), max(dp[2][i][j+1] + dp[1][i+1][j], dp[1][i][j+1] + dp[2][j+1][i]));
            temp = max(temp, max(dp2[3][i][j+1], dp2[3][i-1][j]));
            temp = max(temp, max(dp[1][i][j+1] + dp[1][i][j+1] + dp[1][i-1][j+1], dp[1][i+1][j] + dp[1][i+2][j] + dp[1][i+1][j-1])); // ㅗ, ㅓ
            // dp[4][i][j] = dp[1][i][j] + temp;

            ans = max(ans, dp[1][i][j] + temp);
        }
    }

    cout << ans;

    
}