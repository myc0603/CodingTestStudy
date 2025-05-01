#include <iostream>
using namespace std;

int n, m, nums[2001], dp[2001][2001];

bool isPelin(int s, int e) {
    int mid = (e - s + 1) / 2;
    for (int i = 0; i < mid; ++i) {
        if (nums[s+i] != nums[e-i]) {
            dp[s][e] = 0;
            return false;
        }
    }
    dp[s][e] = 1;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    fill(&dp[0][0], &dp[0][0] + 2001 * 2001, -1);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }
    cin >> m;
    while (m--) {
        int s, e;
        cin >> s >> e;
        if (dp[s][e] != -1) cout << dp[s][e] << '\n';
        else cout << (isPelin(s, e) ? 1 : 0) << '\n';
    }
}