#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, c, w[15], dp[12][22];

int dfs(int bag, int curWeight) {

    if (bag == m) return 1;
    
    int &result = dp[bag][curWeight];
    if (result != -1) return result;

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (curWeight + w[i] <= c) {
            cnt += dfs(bag, curWeight + w[i]);
        } else {
            cnt += dfs(bag + 1, w[i]);
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m >> c;
    for (int i = 0; i < n; ++i) cin >> w[i];

    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0);
}