#include <bits/stdc++.h>
using namespace std;

int main() {
    string ans;
    while (true) {
        string s;
        getline(cin, s);
        if (s[0] == '.') {
            break;
        }

        stack<char> stk;
        for (char c : s) {
            if (c == '.') {
                break;
            }
            if (c == ')' && !stk.empty() && stk.top() == '(') {
                stk.pop();
                continue;
            }
            if (c == ']' && !stk.empty() && stk.top() == '[') {
                stk.pop();
                continue;
            }
            if (c == '(' || c == ')' || c == '[' || c == ']') {
                stk.push(c);
            }
        }
        ans += stk.empty() ? "yes\n" : "no\n";
    }
    cout << ans;
}