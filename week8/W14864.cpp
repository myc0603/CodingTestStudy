#include <iostream>
using namespace std;

int n, m, ans[100002];
bool check[100002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) ans[i] = i;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        ++ans[x];
        --ans[y];
    }

    for (int i = 1; i <= n; ++i) {
        if (check[ans[i]]) {
            cout << -1 << '\n';
            return 0;
        }
        check[ans[i]] = 1;
    }

    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}