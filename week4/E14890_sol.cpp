#include <bits/stdc++.h>
using namespace std;

int n, l, a[100][100], b[100][100];
int ans;

void solve(int a[100][100]) {
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        int prev = a[i][0];
        int j;
        for (j = 1; j < n; j++) {
            int cur = a[i][j];
            if (prev == cur) cnt++;
            else if (prev + 1 == cur && cnt >= l) cnt = 1;
            else if (prev - 1 == cur && cnt >= 0) cnt = -l + 1;
            else break;

            prev = cur;
        }

        if (j == n && cnt >= 0) ans++;
    }
}

int main() {
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }

    solve(a);
    solve(b);
    cout << ans << '\n';
}