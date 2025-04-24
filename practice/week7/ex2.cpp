#include <iostream>
using namespace std;

int t, n, dp[10001];

int main() {
    dp[0] = 1;
    for (int i = 1; i <= 3; i++) {
        for (int j = i; j <= 10000; j++) {
            dp[j] += dp[j - i];
        }
    }

    for (int i = 0; i < 20; i++) {
        cout << "dp[" << i << "] : " << dp[i] << '\n';
    }
}