#include <bits/stdc++.h>
using namespace std;

int n, m, a[50][50];

int count(int y, int x) {
    int check[2][8] = {
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1}
    };
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (a[y+i][x+j] != check[i%2][j]) cnt1++;
            else cnt2++;
        }
    }
    // cout << "cnt1, cnt2: " << cnt1 << ',' << cnt2 << '\n';
    return min(cnt1, cnt2);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] == 'W' ? 1 : 0;
        }
    }

    int ans = m*n;
    for (int i = 0; i + 8 <= n; i++) {
        for (int j = 0; j + 8 <= m; j++) {
            ans = min(count(i, j), ans);
        }
    }
    cout << ans;
}