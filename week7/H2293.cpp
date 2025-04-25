#include <iostream>
using namespace std;

int n, k, coins[100], dp[10001];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> coins[i];

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int val = coins[i];
        if (val > k) continue;
        for (int j = val; j <= k; j++) {
            dp[j] = dp[j - val] + dp[j];
        }
    }

    cout << dp[k];
}