#include <iostream>
#include <cstring>
using namespace std;

int n, scores[303], dp[303][4];

// 마지막 도착 계단은 반드시 밟아야 한다.
int dfs(int idx, int cnt) {
    if (idx > n) return 0;

    int &result = dp[idx][cnt];
    if (result != -1) return result;

    // 마지막 계단을 밟지 못하는 경우
    // 마지막 계단을 밟을 수 있는 데 안 밟는 경우는 최댓값이 될 수 없으니까 신경 안 써도 됨
    if (idx == n - 1 && cnt == 2) return result = -1e9;

    result = dfs(idx + 2, 1) + scores[idx];
    if (cnt < 2) result = max(result, dfs(idx + 1, cnt + 1) + scores[idx]);
    return result;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> scores[i];

    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0);
}