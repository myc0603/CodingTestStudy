#include <iostream>
using namespace std;

int dp[13];

int main() {
    dp[0] = 1;
    for (int i = 1; i <= 11; i++) {
        dp[i] = dp[i-1] + (i >= 2 ? dp[i-2] : 0) + (i >= 3 ? dp[i-3] : 0);
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
}