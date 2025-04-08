#include <bits/stdc++.h>
using namespace std;

int n, a[100000], include[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // long long !!
    long long cnt = 0;

    int l = 0; int r = 0;
    include[a[r]] = 1;
    while (true) {
        cnt += r - l + 1;

        r++;
        if (r >= n) break;
        if (include[a[r]] == 1) {
            while (a[l] != a[r]) {
                include[a[l]] = 0;
                l++;
            }
            l++;
        }
        include[a[r]] = 1;
    }

    cout << cnt;
}