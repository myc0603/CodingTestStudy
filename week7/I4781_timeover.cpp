#include <iostream>
#include <vector>
using namespace std;

int n, c;
double m, p;
vector<pair<int, int>> candies; // calory, price
int dp[5000][10001];

int calories(int idx, int remainPrice) {
    if (remainPrice == 0) return 0;
    if (remainPrice < 0) return -1e9;
    if (idx == n) return 0;

    int candyCalory = candies[idx].first;
    int candyPrice = candies[idx].second;
    cout << "calory: " << candyCalory << ", price: " << candyPrice << '\n';

    int &result = dp[idx][remainPrice];
    if (result != -1) return result;

    result = 0;
    int maxCnt = remainPrice / candyPrice;
    for (int cnt = 0; cnt <= maxCnt; cnt++) {
        int curCandyCalory = cnt * candyCalory;
        int nextCalories = calories(idx + 1, remainPrice - candyPrice * cnt);
        result = max(result, nextCalories + curCandyCalory);
        
        cout << "  result: " << result << '\n';
    }
    cout << "return\n";
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string ans;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        m *= 100;
        for (int i = 0; i < n; i++) {
            cin >> c >> p;
            candies.push_back( {c, 100 * p} );
        }

        fill(&dp[0][0], &dp[0][0] + 5000 * 10001, -1);
        ans += to_string(calories(0, m)) + '\n';
        candies.clear();
    }
    cout << ans;
}