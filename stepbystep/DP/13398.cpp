#include <iostream>
using namespace std;

int n, a[100002], dp[2][100002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int sum = -1e9;
    dp[0][0] = a[0];
    // dp[1][0] = 0; // 맨 앞에껄 제거하는 거는 제거 안한거랑 다름없음
    // dp[1][0] = a[0]; // 이게 왜 되는지는 잘 모르겠네
    dp[1][0] = -1e9;
    for (int i = 1; i < n; ++i) {
        dp[0][i] = max(dp[0][i-1], 0) + a[i];
        dp[1][i] = max(dp[0][i-1], dp[1][i-1] + a[i]);
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            sum = max(dp[i][j], sum);
        }
    }
    cout << sum;
}