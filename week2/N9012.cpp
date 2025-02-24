#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    string ans;
    while (n--) {
        string s; cin >> s;

        stack<char> stk;
        for (char c : s) {
            if (!stk.empty() && stk.top() == '(' && c == ')') {
                stk.pop();
                continue;
            }
            stk.push(c);
        }
        ans += stk.empty() ? "YES\n" : "NO\n";
    }
    cout << ans;
}