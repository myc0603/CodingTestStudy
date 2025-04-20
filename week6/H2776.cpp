#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int n, m, a[1000002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ostringstream oss;
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);

        cin >> m;
        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            auto it = lower_bound(a, a + n, x);
            if (it == a + n || *it != x) {
                oss << "0\n";
            } else {
                oss << "1\n";
            }
        }
    }
    cout << oss.str();
}