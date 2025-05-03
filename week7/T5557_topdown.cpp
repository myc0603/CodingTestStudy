#include <iostream>
using namespace std;

int n, last, a[105];
long long dp[105][25];

long long dfs(int idx, int sum) {
    if (sum < 0 || sum > 20) return 0;
    if (idx == n) {
        if (sum == last) return 1;
        else return 0;
    }

    long long &cnt = dp[idx][sum];
    if (cnt != -1) return cnt;

    cnt = dfs(idx + 1, sum + a[idx]) + dfs(idx + 1, sum - a[idx]);
    return cnt;
}

int main() {
    cin >> n;
    --n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> last;

    fill(&dp[0][0], &dp[0][0] + 105 * 25, -1);
    // cout << dfs(0, 0);
    cout << dfs(1, a[0]);
}