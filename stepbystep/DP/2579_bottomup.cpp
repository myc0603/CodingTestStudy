#include <iostream>
using namespace std;

int n, scores[303], dp[303][4];

// 마지막 도착 계단은 반드시 밟아야 한다.
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> scores[i];

    dp[1][1] = scores[1];

    for (int i = 1; i <= n; ++i) {
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + scores[i];
        dp[i][2] = dp[i-1][1] + scores[i];
    }

    cout << max(dp[n][1], dp[n][2]);
}