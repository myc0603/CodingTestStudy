#include <iostream>
#include <cstring>
using namespace std;

int n, k, wt[101], wv[101], bt[101], bv[101], dp[101][100003];

int dfs(int idx, int t) {
    if (t > k) return -1e9;
    if (idx == n) return 0;

    int &result = dp[idx][t];
    if (result != -1) return result;

    result = max(dfs(idx + 1, t + wt[idx]) + wv[idx], dfs(idx + 1, t + bt[idx]) + bv[idx]);
    return result;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> wt[i] >> wv[i] >> bt[i] >> bv[i];

    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0);
}