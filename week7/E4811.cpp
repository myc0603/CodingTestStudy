#include <iostream>
using namespace std;

long long dp[31][31];

long long sol(int whole, int half) {
    if (half < 0) return 0;
    if (whole == 0) return 1;

    long long &result = dp[whole][half];
    if (result != -1) return result;
    result = sol(whole - 1, half + 1) + sol(whole, half - 1);
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill(&dp[0][0], &dp[0][0] + 31 * 31, -1);

    string ans;
    while (true) {
        int n; cin >> n;
        if (n == 0) break;

        ans += to_string(sol(n, 0)) + '\n';
    }
    cout << ans;
}