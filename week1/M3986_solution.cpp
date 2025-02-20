#include <bits/stdc++.h>
using namespace std;

// using stack

bool isGood(string s) {
    stack<char> stk;
    for (char c: s) {
        if (!stk.empty() && stk.top() == c) {
            stk.pop();
        } else {
            stk.push(c);
        }
    }
    return stk.empty() ? true : false;
}

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (isGood(s)) {
            cnt++;
        }
    }
    cout << cnt << '\n';
}