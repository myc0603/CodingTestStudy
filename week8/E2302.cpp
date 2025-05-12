#include <iostream>
using namespace std;

int n, m, dp[42], cnt = 1;

int main () {
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) dp[i] = dp[i-1] + dp[i-2];

    cin >> m;
    int pre = 0;
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        cnt *= dp[x-pre-1];
        pre = x;
    }
    cnt *= dp[n-pre];
    cout << cnt;
}