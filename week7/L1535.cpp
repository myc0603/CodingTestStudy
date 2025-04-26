#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> lost(n), joy(n);
    for (int &l : lost) cin >> l;
    for (int &j : joy) cin >> j;

    vector<int> dp(100); // 일단 0으로 초기화

    for (int i = 0; i < n; i++) {
        int l = lost[i];
        int j = joy[i];

        for (int k = 99; k >= l; k--) {
            dp[k] = max(dp[k - l] + j, dp[k]);
        }
    }
    
    cout << dp[99];
}