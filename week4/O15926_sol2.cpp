#include <bits/stdc++.h>
using namespace std;

int n, ans;
string s;

int main() {
    cin >> n >> s;
    
    stack<int> stk;
    stk.push(-1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') stk.push(i);
        else {
            stk.pop();
            if (stk.empty()) stk.push(i);
            else ans = max(ans, i - stk.top());
        }
    }
    cout << ans << '\n';
}