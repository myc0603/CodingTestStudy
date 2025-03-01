#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[n][m];
    memset(a, -1, sizeof(a));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;

        // v1
        // int idx = -1;
        // for (int j = 0; j < m; j++) {
        //     if (s[j] == 'c') {
        //         a[i][j] = 0;
        //         idx = j;
        //     } else if (idx != -1) {
        //         a[i][j] = j - idx;
        //     }
        // }

        // v2
        for (int j = 0; j < m; j++) {
            if (s[j] == 'c') {
                a[i][j] = 0;
                int cnt = 0;
                while (s[j+1] == '.') {
                    a[i][j+1] = ++cnt;
                    j++;
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