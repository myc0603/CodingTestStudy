#include <bits/stdc++.h>
using namespace std;

int n, a[500004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int maxBtw = 0;
        for (int j = i + 1; a[i] >= maxBtw && j < n; j++) {
            if (a[j] >= maxBtw) cnt++;
            maxBtw = max(a[j], maxBtw);
        }
    }
    cout << cnt << '\n';
}