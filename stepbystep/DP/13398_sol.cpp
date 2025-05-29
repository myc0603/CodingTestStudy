#include <iostream>
using namespace std;

int n, a[100002], dp1[100002], dp2[100002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int sum = -1e9;
    dp1[0] = a[0];
    for (int i = 1; i < n; ++i) {
        dp1[i] = max(dp1[i-1] + a[i], a[i]);
    }
    dp2[n-1] = a[n-1];
    for (int i = n - 2; i >= 0; --i) {
        dp2[i] = max(dp2[i+1] + a[i], a[i]);
    }

    int result = -1e9;
    for (int i = 0; i < n; ++i) result = max(result, dp1[i]);
    for (int i = 1; i < n - 1; ++i) {
        result = max(result, dp1[i-1] + dp2[i+1]);
    }
    cout << result;
}