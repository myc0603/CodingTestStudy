#include <bits/stdc++.h>
using namespace std;

string s, bomb;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> bomb;

    stack<char> stk;
    for (char c : s) {
        if (c == bomb[bomb.size()-1]) {
            string temp;
            temp += c;
            while (temp.size() < bomb.size() && stk.size()) {
                temp += stk.top();
                stk.pop();
            }
            reverse(temp.begin(), temp.end());
            if (temp != bomb) {
                for (char t : temp) {
                    stk.push(t);
                }
            }
            continue;
        }
        stk.push(c);
    }

    if (stk.empty()) cout << "FRULA";
    else {
        string ans;
        while (stk.size()) {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
    return 0;
}