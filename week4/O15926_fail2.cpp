#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    cin >> n >> s;

    int ans = 0;
    int cnt = 0;
    stack<char> stk;
    for (char c : s) {
        if (c == '(') {
            stk.push(c);
        } else {
            if (stk.empty()) {
                cnt = 0;
            } else {
                cnt += 2;
                stk.pop();
                ans = max(ans, cnt);
            }
        }
    }

    cout << ans << '\n';
}