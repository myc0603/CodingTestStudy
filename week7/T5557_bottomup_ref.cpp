#include <iostream>
using namespace std;

int n, last, a[105];
long long dp[105][25]; // idx까지 와서 sum이 되는 경우의 수


int main() {
    cin >> n;
    --n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> last;

    dp[0][a[0]] = 1;
    for (int i = 1; i < n; ++i) {
        for (int sum = 0; sum <= 20; ++sum) {
            if (sum + a[i] <= 20) {
                dp[i][sum + a[i]] += dp[i-1][sum];
            }

            if (sum - a[i] >= 0) {
                dp[i][sum - a[i]] += dp[i-1][sum];
            }
        }
    }
    cout << dp[n-1][last];
}