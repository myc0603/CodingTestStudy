#include <bits/stdc++.h>
using namespace std;

bool isGood(string s) {
    stack<char> stk;
    for (char c : s) {
        if (!stk.empty() && stk.top() == c) {
            stk.pop();
        } else stk.push(c);
    }
    return stk.empty();
}
int main() {
    int n; cin >> n;

    int cnt = 0;
    while (n--) {
        string s; cin >> s;
        if (isGood(s)) cnt++;
    }
    cout << cnt << '\n';
}