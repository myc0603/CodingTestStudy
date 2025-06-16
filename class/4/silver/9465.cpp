#include <iostream>
using namespace std;

int t, n, a[2][100003], dp[2][100003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < 2; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> a[i][j];
            }
        }

        dp[0][1] = a[0][1];
        dp[1][1] = a[1][1];

        for (int j = 2; j <= n; ++j) {
            dp[0][j] = max(dp[1][j-1], dp[1][j-2]) + a[0][j];
            dp[1][j] = max(dp[0][j-1], dp[0][j-2]) + a[1][j];
        }
        cout << max(dp[0][n], dp[1][n]) << '\n';
    }
}