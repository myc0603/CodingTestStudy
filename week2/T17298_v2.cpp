#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n; // 100만...
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans[n];
    // memset(ans, -1, sizeof(ans)); // 0, -1만 가능
    fill(ans, ans + n, -1);

    // 아마 안될듯 시간 복잡도 너무 커짐
    queue<int> q;
    q.push(0);
    for (int i = 1; i < n; i++) {
        vector<int> fail;
        while (q.size()) {
            int idx = q.front(); q.pop();
            if (a[idx] < a[i]) {
                ans[idx] = a[i];
            } else {
                fail.push_back(idx);
            }
        }
        for (int num : fail) {
            q.push(num);
        }
        q.push(i);
    }


    string s;
    for (int num : ans) {
        s += to_string(num) + ' ';
    }
    cout << s;
}