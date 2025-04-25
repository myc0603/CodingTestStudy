#include <iostream>
using namespace std;

const int INF = 1e9;
int n, k, coins[100], dp[10002];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    fill(dp, dp + 10002, INF);

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int val = coins[i];
        if (val > k) continue;
        dp[val] = 1;
        for (int j = val + 1; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - val] + dp[val]);
        }
    }

    if (dp[k] == INF) cout << -1;
    else cout << dp[k];
}