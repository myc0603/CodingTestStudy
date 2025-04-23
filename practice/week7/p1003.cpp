#include <bits/stdc++.h>
using namespace std;

int x, cnt0, cnt1, dp[44][2];

pair<int, int> f(int n) {
    if (n == 1) return {0, 1};
    if (n == 0) return {1, 0};
    if (dp[n][0] == 0 && dp[n][1] == 0) {
        dp[n][0] = f(n - 1).first + f(n - 2).first;
        dp[n][1] = f(n - 1).second + f(n - 2).second;
    }
    return {dp[n][0], dp[n][1]};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    dp[0][0] = 1;
    dp[1][1] = 1;
    string ans;
    while (t--) {
        cin >> x;
        auto p = f(x);
        ans += to_string(p.first) + ' ' + to_string(p.second) + '\n';
    }
    cout << ans;
}