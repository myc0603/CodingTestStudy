#include <bits/stdc++.h>
using namespace std;

int n, m, a[4][4];

int sum(int cases) {
    int result = 0;

    for (int i = 0; i < n; i++) {
        int num = 0;
        for (int j = 0; j < m; j++) {
            int idx = i * m + j;
            if (cases & (1 << idx)) { // 1
                result += num;
                num = 0;
            } else { // 0
                num = 10 * num + a[i][j];
            }
        }
        result += num;
    }
    
    for (int j = 0; j < m; j++) {
        int num = 0;
        for (int i = 0; i < n; i++) {
            int idx = i * m + j;
            if (cases & (1 << idx)) { // 1
                num = 10 * num + a[i][j];
            } else { // 0
                result += num;
                num = 0;
            }
        }
        result += num;
    }

    return result;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << (n*m)); i++) {
        ans = max(sum(i), ans);
    }
    cout << ans << '\n';
}