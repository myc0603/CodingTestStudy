#include <iostream>
#include <vector>
using namespace std;

int n, w, dp[1002][1002], nextArr[1002][1002];
vector<pair<int, int>> cases;

int dis(int i1, int i2) {
    auto p1 = cases[i1], p2 = cases[i2];
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int dfs(int car1, int car2) {
    int cur = max(car1, car2) + 1;
    if (cur == w + 2) return 0;

    int &result = dp[car1][car2];
    if (result != -1) return result;

    int dis1 = dfs(cur, car2) + dis(car1, cur); // car1 -> cur
    int dis2 = dfs(car1, cur) + dis(car2, cur); // car2 -> cur
    if (dis1 < dis2) {
        result = dis1;
        nextArr[car1][car2] = 1;
    } else {
        result = dis2;
        nextArr[car1][car2] = 2;
    }
    return result;
}

void printOrder() {
    vector<int> order;

    int car1 = 0, car2 = 1, cur = 2;
    while (cur <= w + 1) {
        cout << "car1: " << car1 << ", car2: " << car2 << '\n';
        cout << "dp[car1][car2]: " << dp[car1][car2] << '\n';
        cout << "dp[cur][car2] + dis(car1, cur): " << dp[cur][car2] + dis(car1, cur) << '\n';
        cout << "dp[car1][cur] + dis(car2, cur): " << dp[car1][cur] + dis(car2, cur) << "\n\n";
        // if (dp[car1][car2] == dp[cur][car2] + dis(car1, cur)) {
        if (dp[cur][car2] + dis(car1, cur) < dp[car1][cur] + dis(car2, cur)) {
            order.push_back(1);
            car1 = cur;
        } else {
            order.push_back(2);
            car2 = cur;
        }
        ++cur;
    }
    for (int car : order) cout << car << '\n';
}

void printOrderUsingNextArr() {
    vector<int> order;

    int car1 = 0, car2 = 1, cur = 2;
    while (cur <= w + 1) {
        int nextCar = nextArr[car1][car2];
        if (nextCar == 1) {
            order.push_back(1);
            car1 = cur;
        } else {
            order.push_back(2);
            car2 = cur;
        }
        ++cur;
    }
    for (int car : order) cout << car << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> w;
    cases.reserve(w + 1);
    cases.emplace_back(1, 1);
    cases.emplace_back(n, n);
    for (int i = 0; i < w; ++i) {
        int y, x;
        cin >> y >> x;
        cases.emplace_back(y, x);
    }

    fill(&dp[0][0], &dp[0][0] + 1002 * 1002, -1);
    cout << dfs(0, 1) << '\n';
    printOrder();
    // printOrderUsingNextArr();
}