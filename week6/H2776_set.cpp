#include <iostream>
#include <unordered_set>
using namespace std;

int n, m;
unordered_set<int> set;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string ans;
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            set.insert(x);
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            if (set.count(x)) {
                ans += to_string(1) + '\n';
            } else {
                ans += to_string(0) + '\n';
            }
        }
        set.clear();
    }
    cout << ans;
}