#include <bits/stdc++.h>
using namespace std;

int n, a[500004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long cnt = 0;
    stack<pair<int, int>> stk;
    for (int i = 0; i < n; i++) {
        while (stk.size() && stk.top().first < a[i]) {
            cnt += stk.top().second;
            stk.pop();
            cnt++; // a[i]와 짝지어져서 1이 더해진다.
        }
        if (stk.empty()) {
            stk.push({a[i], 0});
        } else if (stk.top().first > a[i]) {
            stk.push({a[i], 1});
        } else { // 같을 때
            stk.push({a[i], 1 + stk.top().second});
        }
    }
    while (stk.size()) {
        cnt += stk.top().second;
        stk.pop();
    }

    cout << cnt << '\n';
}