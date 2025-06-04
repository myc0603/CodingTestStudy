#include <iostream>
using namespace std;

int n, m, a[100003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        a[i] = a[i-1] + x;
    }

    for (int i = 0; i < m; ++i) {
        int s, e;
        cin >> s >> e;
        cout << a[e] - a[s-1] << '\n';
    }
}