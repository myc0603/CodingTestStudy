#include <iostream>
using namespace std;

int n, dp[2502];
string s;

void initDpAroundCenter(int l, int r) {
    while (l >= 0 && r < n && s[l] == s[r]) {
        dp[r+1] = min(dp[r+1], dp[l] + 1);
        --l; ++r;
    }
    // dp[r] = min(dp[r], dp[l+1] + 1);
}

int main() {
    cin >> s;
    n = s.length();

    fill(dp, dp + 2502, 1e9);
    dp[0] = 0;

    for (int center = 0; center < n; ++center) {
        initDpAroundCenter(center, center); // for odd pelindrom
        initDpAroundCenter(center, center + 1); // for even pelindrom
    }

    cout << dp[n];
}