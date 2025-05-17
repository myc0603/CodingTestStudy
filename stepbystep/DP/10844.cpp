#include <iostream>
using namespace std;
const int MOD = 1e9;
int n, dp[101][11], ans;
int main() {
    for (int j = 0; j <= 9; ++j) dp[1][j] = 1;
    for (int i = 2; i <= 100; ++i) {
        for (int j = 0; j <= 9; ++j) {
            dp[i][j] = dp[i-1][j+1];
            if (j != 0) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
        }
    }
    cin >> n;
    for (int j = 1; j <= 9; ++j) ans = (ans + dp[n][j]) % MOD;
    cout << ans;
}