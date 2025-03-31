#include <bits/stdc++.h>
using namespace std;

int n, check[200000], cnt, ans;
string s;

int main() {
    cin >> n >> s;
    
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') stk.push(i);
        else if (stk.size()) {
            check[i] = 1;
            check[stk.top()] = 1;
            stk.pop();
        }
    }
    for (int i = 0; i < n; i++) {
        if (check[i]) {
            cnt++;
            ans = max(cnt, ans);
        }
        else cnt = 0;
    }
    cout << ans << '\n';
}