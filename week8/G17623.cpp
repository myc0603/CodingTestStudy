#include <iostream>
using namespace std;

string dp[1002];
int dmap[256];

bool operator<(string &s1, string &s2) {
    if (s1.size() != s2.size()) return s1.size() < s2.size();
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] == s2[i]) continue;
        return dmap[s1[i]] < dmap[s2[i]];
    }
    return false;
}

int main() {
    dmap['('] = 1; dmap[')'] = 2;
    dmap['{'] = 3; dmap['}'] = 4;
    dmap['['] = 5; dmap[']'] = 6;

    dp[1] = "()"; dp[2] = "{}"; dp[3] = "[]";
    for (int i = 4; i <= 1000; ++i) {
        dp[i] = dp[1] + dp[i-1];
        string t = dp[i-1] + dp[1];
        if (t < dp[i]) dp[i] = t;
        for (int j = 2; j <= i / 2; ++j) {
            t = dp[j] + dp[i-j];
            if (t < dp[i]) dp[i] = t;

            t = dp[i-j] + dp[j];
            if (t < dp[i]) dp[i] = t;
        }

        t = "(" + dp[i / 2] + ")"; 
        if (i % 2 == 0 && t < dp[i]) dp[i] = t;

        t = "{" + dp[i / 3] + "}"; 
        if (i % 3 == 0 && t < dp[i]) dp[i] = t;

        t = "[" + dp[i / 5] + "]"; 
        if (i % 5 == 0 && t < dp[i]) dp[i] = t;
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
}