#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> coins(n); // value, count
    for (auto &c : coins) cin >> c.first >> c.second;

    vector<long long> dp(k + 1);
    dp[0] = 1;
    for (auto c : coins) {
        int val = c.first;
        int cnt = c.second;

        for (int r = 0; r < val; r++) {
            long long acc = 0;
            queue<long long> q;
            for (int j = r; j <= k; j += val) {
                acc += dp[j];
                q.push(dp[j]);

                if (q.size() > cnt + 1) {
                    acc -= q.front();
                    q.pop();
                }

                dp[j] = acc;
            }
        }
    }

    cout << dp[k];
}