#include <iostream>
#include <algorithm>
using namespace std;
int n, a[1002];
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; ++i) ans += a[i] * (n - i);
    cout << ans;
}