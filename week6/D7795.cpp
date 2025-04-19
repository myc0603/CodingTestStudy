#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a[20002], b[20002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    string ans;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        sort(a, a + n);
        sort(b, b + m);

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(b, b + m, a[i]);
            cnt += it - b;
        }
        ans += to_string(cnt) + '\n';
    }
    cout << ans;
}