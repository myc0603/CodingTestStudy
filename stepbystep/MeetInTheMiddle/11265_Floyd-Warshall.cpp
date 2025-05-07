#include <iostream>
using namespace std;

const string ENJOY = "Enjoy other party\n", STAY = "Stay here\n";
int n, m, t[502][502];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> t[i][j];
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                t[i][j] = min(t[i][j], t[i][k] + t[k][j]);
            }
        }
    }

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (t[a][b] <= c) cout << ENJOY;
        else cout << STAY;
    }
}