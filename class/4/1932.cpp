#include <iostream>
#include <cstring>
using namespace std;

int n, a[502][502], dp[502][502];

int dfs(int floor, int idx) {
    if (floor == n - 1) return a[floor][idx];

    int &result = dp[floor][idx];
    if (result != -1) return result;

    result = dfs(floor + 1, idx) + a[floor][idx];
    result = max(result, dfs(floor + 1, idx + 1)+ a[floor][idx]);
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0);
}