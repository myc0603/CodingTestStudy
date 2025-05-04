#include <iostream>
using namespace std;

int n, isPelin[2502][2502], dp[2502];
string s;

void initIsPelin() {
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

int main() {
    cin >> s;
    n = s.length();
    initIsPelin();

    fill(dp, dp + 2502, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (isPelin[j][i-1]) dp[i] = min(dp[j] + 1, dp[i]);
        }
    }

    cout << dp[n];
}