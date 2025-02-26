#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;

    stack<pair<int, int>> stk; // idx, num
    int ans[n];
    for (int i = 0; i < n; i++) {
        
        int num; cin >> num;
        
        while (stk.size() && stk.top().second < num) {
            ans[stk.top().first] = num;
            stk.pop();
        }
        stk.push({i, num});
    }

    while (stk.size()) {
        ans[stk.top().first] = -1;
        stk.pop();
    }

    string s;
    for (int num : ans) {
        s += to_string(num) + ' ';
    }
    cout << s;
}