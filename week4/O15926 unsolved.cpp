#include <bits/stdc++.h>
using namespace std;

// (()( -> 2가 나와야 되는데 이 코드의 결과는 0
int main() {
    int n; cin >> n;
    string s; cin >> s;

    stack<char> stk;
    int temp = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        // cout << i << ": " << s[i];
        if (s[i] == '(') {
            // cout << " -> stk.push and temp++\n";
            stk.push(s[i]);
            temp++;
        } else if (!stk.empty()) {
            // cout << " -> stk.pop and temp++\n";
            stk.pop();
            temp++;
            if (stk.empty()) {
                cnt = max(cnt, temp);
                // cout << "  update temp: " << temp << ", cnt: " << cnt << '\n';
            }
        } else {
            // cout << " -> temp = 0 ans stk.clear\n";
            temp = 0;
            while (stk.size()) stk.pop();
        }
    }
    cout << cnt << '\n';
}