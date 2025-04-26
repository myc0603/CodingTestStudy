#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T, k;
    cin >> T >> k;
    vector<pair<int, int>> coins(k); // value, count
    for (auto &c : coins) cin >> c.first >> c.second;

    vector<long long> dp(T + 1);
    dp[0] = 1;
    for (auto c : coins) {
        int val = c.first;
        int cnt = c.second;

        for (int j = T; j >= 0; j--) {
            for (int l = 1; l <= cnt; l++) {
                if (j - val * l < 0) break;
                dp[j] += dp[j - val*l];
            }
        }
    }

    cout << dp[T];
}