#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> objs(n); // weight, value
    for (auto &obj : objs) cin >> obj.first >> obj.second;

    vector<int> dp(k + 1);
    for (auto obj : objs) {
        for (int i = k; i >= obj.first; i--) {
            dp[i] = max(dp[i], dp[i-obj.first] + obj.second);
        }
    }
    cout << dp[k];
}