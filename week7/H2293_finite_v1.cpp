#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> coins(n + 1); // value, number
    for (int i = 1; i <= n; i++) cin >> coins[i].first >> coins[i].second;

    // dp[i][j]: i번째 동전까지 살펴봤을 때 금액 j를 만드는 경우의 수
    vector<vector<int>> dp(n + 1, vector<int>(k + 1)); // coin idx, 총 금액
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        int val = coins[i].first;
        int cnt = coins[i].second;

        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i-1][j]; // coins[i] 사용 안 한 경우
            for (int t = 1; t <= cnt && j >= t * val; ++t) {
                dp[i][j] += dp[i-1][j - t*val]; // coins[i]를 t개 사용하는 경우
            }
        }
    }

    cout << dp[n][k];
}