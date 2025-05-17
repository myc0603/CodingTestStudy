#include <iostream>
using namespace std;

int n, wines[10003], dp[10003][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> wines[i];

    dp[1][1] = wines[1];
    dp[2][1] = wines[2];
    dp[2][2] = dp[1][1] + wines[2];
    for (int i = 3; i <= n; ++i) {
        dp[i][1] = max(max(dp[i-2][1], dp[i-2][2]), max(dp[i-3][1], dp[i-3][2])) + wines[i];
        dp[i][2] = dp[i-1][1] + wines[i];
    }

    cout << max(max(dp[n][1], dp[n][2]), dp[n-1][2]);
}