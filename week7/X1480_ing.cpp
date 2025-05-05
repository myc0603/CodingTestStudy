#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, c;
vector<int> w, dp[22];

int main() {
    cin >> n >> m >> c;
    w.resize(n);
    for (int i = 0; i < n; ++i) cin >> w[i];

    int cnt = 0;
    // m으로도 루프 돌아야 됨
    while (m--) {
        for (int weight : w) {
            for (int j = c; j >= weight; --j) {
                if (dp[j].size() < dp[j-weight].size() + 1) {
                    dp[j] = dp[j-weight];
                    dp[j].push_back(weight);
                }
            }
        }

        cnt += dp[c].size();
        for (int jewel : dp[c]) w.erase(find(w.begin(), w.end(), jewel));
        for (auto &v : dp) v.clear();
    }
    cout << cnt;
}