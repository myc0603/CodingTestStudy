#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for (int &c : coins) cin >> c;

    const int INF = 1e9;
    vector<int> dp(k + 1);
    dp[0] = 1;

    for (int c : coins) {
        for (int i = c; i <= k; i++) {
            dp[i] += dp[i-c];
        }
    }
    cout << dp[k];
}