#include <iostream>
#include <map>
using namespace std;

int n, c, weights[31];
map<pair<int, long long>, long long> dp;

// top-down
long long dfs(int idx, long long sum) {
    if (idx == n) return sum <= c ? 1 : 0;

    if (dp.find({idx, sum}) != dp.end()) return dp[{idx, sum}];

    dp[{idx, sum}] = dfs(idx + 1, sum + weights[idx]) + dfs(idx + 1, sum);
    return dp[{idx, sum}];
}

int main() {
    cin >> n >> c;
    for (int i = 0; i < n; ++i) cin >> weights[i];

    cout << dfs(0, 0);
}