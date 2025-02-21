#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt[26] = {};
    while (n--) {
        string s;
        cin >> s;
        cnt[s[0]-'a']++;
    }
    string ans = "";
    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= 5) {
            ans += i + 'a';
        }
    }
    ans = ans.size() == 0 ? "PREDAJA" : ans;
    cout << ans << '\n';
}