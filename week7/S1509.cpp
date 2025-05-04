#include <iostream>
using namespace std;

int n, isPelin[2502][2502], dp[2502];
string s;

void initDp() {
    for (int i = 0; i < n; ++i) {
        isPelin[i][i] = 1;
        if (i > 0 && s[i-1] == s[i]) isPelin[i-1][i] = 1;
        if (i > 1) {
            for (int j = 0; j <= i - 2; ++j) {
                if (s[j] == s[i] && isPelin[j+1][i-1]) isPelin[j][i] = 1;
            }
        }
    }
}

int dfs(int idx) {
    if (idx >= n) return 0;

    int &cnt = dp[idx];
    if (cnt != -1) return cnt;

    cnt = n + 1;
    for (int i = n - 1; i >= idx; --i) {
        if (isPelin[idx][i] == 0) continue;
        cnt = min(dfs(i + 1) + 1, cnt);
    }
    return cnt;
}

int main() {
    cin >> s;
    n = s.length();
    initDp();

    fill(dp, dp + 2502, -1);
    cout << dfs(0);
}