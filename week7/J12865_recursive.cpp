#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<pair<int, int>> objs; // weight, value
int dp[102][100002];

int go(int idx, int weight) {
    if (weight > k) return -1e9;
    if (weight == k || idx == n) return 0;

    int &res = dp[idx][weight];
    if (res != -1) return res;

    res = max(go(idx + 1, weight), go(idx + 1, weight + objs[idx].first) + objs[idx].second);
    return res;
}

int main() {
    cin >> n >> k;
    objs.resize(n);
    for (auto &obj : objs) cin >> obj.first >> obj.second;

    fill(&dp[0][0], &dp[0][0] + 102 * 100002, -1);

    cout << go(0, 0);
}