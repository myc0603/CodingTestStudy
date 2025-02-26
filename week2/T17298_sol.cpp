#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;

    stack<int> stk; // 인덱스를 넣는다.
    int a[n], ans[n];
    fill(ans, ans + n, -1); // 오큰수 못찾으면 못 찾는대로 -1
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        while (stk.size() && a[stk.top()] < a[i]) {
            ans[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);
    }


    string s;
    for (int num : ans) {
        s += to_string(num) + ' ';
    }
    cout << s;
}