#include <bits/stdc++.h>
using namespace std;

int n, temp;
long long cnt;
stack<pair<int, int>> stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    while (n--) {
        cin >> temp;
        while (stk.size() && stk.top().first < temp) {
            cnt += stk.top().second;
            stk.pop();
            cnt++;
        }
        if (stk.empty()) stk.push({temp, 0});
        else if (stk.top().first > temp) stk.push({temp, 1});
        else stk.push({temp, 1 + stk.top().second});
    }
    while (stk.size()) {
        cnt += stk.top().second;
        stk.pop();
    }
    cout << cnt << '\n';
}