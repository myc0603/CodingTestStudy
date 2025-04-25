#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;
int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for (int &c : coins) cin >> c;

    vector<int> dp(k + 1, INF);
    dp[0] = 0;
    for (int &c : coins) {
        for (int i = c; i <= k; i++) {
            dp[i] = min(dp[i], dp[i-c] + 1);
        }
    }

    if (dp[k] == INF) cout << -1;
    else cout << dp[k];
}