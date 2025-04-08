#include <bits/stdc++.h>
using namespace std;

int n, x, a[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;

    sort(a, a + n);

    int cnt = 0;
    int l = 0; int r = n - 1;
    while (l < r) {
        int sum = a[l] + a[r];
        if (sum == x) {
            cnt++;
            l++;
        } else if (sum > x) {
            r--;
        } else {
            l++;
        }
    }
    cout << cnt;
}