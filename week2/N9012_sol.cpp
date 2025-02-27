#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    string ans;
    while (n--) {
        string s; cin >> s;

        stack<char> stk;
        bool valid = true;
        for (char c : s) {
            if (c == '(') {
                stk.push(c);
            } else if (stk.empty()) {
                valid = false;
                break;
            } else {
                stk.pop();
            }
            // if (c == ')') {
            //     if (stk.empty()) {
            //         valid = false;
            //         break;
            //     }
            //     stk.pop();
            // } else {
            //     stk.push(c);
            // }
            
        }
        ans += valid && stk.empty() ? "YES\n" : "NO\n";
    }
    cout << ans;
}