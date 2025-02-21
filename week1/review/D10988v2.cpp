#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.size();
    bool ans = true;
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len-1-i]) {
            ans = false;
            break;
        }
    }
    cout << ans << '\n';
}