#include <bits/stdc++.h>
using namespace std;

int n, m, a[100][100];

int main() {
    cin >> n >> m;

    memset(a, -1, sizeof(a));

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {

            for (int cnt = 0; cnt <= j; cnt++) {
                if (s[j-cnt] == 'c') {
                    a[i][j] = cnt;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}