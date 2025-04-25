#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string ans;
    while (true) {
        int n, m; double inputM;
        cin >> n >> inputM;
        if (n == 0 && inputM == 0) break;
        m = static_cast<int>(inputM * 100 + 0.5);

        vector<pair<int, int>> candies(n); // calory, price
        for (auto &candy : candies) {
            double p;
            cin >> candy.first >> p;
            candy.second = static_cast<int>(p * 100 + 0.5);
        }

        // cout << "check candies\n";
        // for (auto p : candies) {
        //     cout << p.first << ", " << p.second << "\n";
        // }

        vector<int> dp(m + 1);
        for (auto &candy : candies) {
            int cal = candy.first;
            int price = candy.second;

            for (int j = price; j <= m; j++) {
                // cout << "dp[" << j << "]: " << dp[j] << ", dp[" << j - price << "] + " << cal << ": " << dp[j-price] + cal << '\n';
                dp[j] = max(dp[j], dp[j - price] + cal);
            }
        }
        // cout << dp[m] << '\n';
        ans += to_string(dp[m]) + '\n';
    }

    cout << ans;
}