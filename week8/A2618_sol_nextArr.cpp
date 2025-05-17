#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;

int n, w, dp[1002][1002], nxt[1002][1002];
vector<pair<int, int>> positions;

int dis(int i1, int i2) {
    auto p1 = positions[i1];
    auto p2 = positions[i2];
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int dfs(int car1, int car2) {
    int cur = max(car1, car2) + 1;
    if (cur == w + 2) return 0;

    int &result = dp[car1][car2];
    if (result != -1) return result;

    int r1 = dfs(cur, car2) + dis(cur, car1);
    int r2 = dfs(car1, cur) + dis(cur, car2);
    result = r1 < r2 ? r1 : r2;
    nxt[car1][car2] = r1 < r2 ? 1 : 2;
    return result;
}

void printOrder() {
    vector<int> order;
    int car1 = 0, car2 = 1, cur = 2;
    while (cur != w + 2) {
        int nextCar = nxt[car1][car2];
        order.push_back(nextCar);

        if (nextCar == 1) car1 = cur;
        else if (nextCar == 2) car2 = cur;
        else assert(0);
        ++cur;
    }

    for (int x : order) cout << x << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> w;
    positions.reserve(w + 2);
    positions.emplace_back(1, 1);
    positions.emplace_back(n, n);
    for (int i = 0; i < w; ++i) {
        int y, x;
        cin >> y >> x;
        positions.emplace_back(y, x);
    }
    
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 1) << '\n';
    printOrder();
}