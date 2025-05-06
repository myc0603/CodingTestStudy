#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, c, w[15];
int dp[12][22][1 << 13];
// int dp[1 << 13][22][12];

int dfs(int bag, int curWeight, int used) {
    // if (bag == m) return 0; -> 함수 호출하고 바로 리턴하는 것보다 미리 조건 확인하고 함수 호출 안하는게 훨 빠름
    
    int &result = dp[used][curWeight][bag];
    if (result != -1) return result;

    // result = max(result, dfs(bag + 1, 0, used));
    for (int i = 0; i < n; ++i) {
        if (used & (1 << i)) continue;
        if (curWeight + w[i] <= c) {
            result = max(result, dfs(bag, curWeight + w[i], used | (1 << i)) + 1);
        } else if (bag + 1 < m && w[i] <= c) {
            result = max(result, dfs(bag + 1, w[i], used | (1 << i)) + 1);
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> c;
    for (int i = 0; i < n; ++i) cin >> w[i];

    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0, 0);
}