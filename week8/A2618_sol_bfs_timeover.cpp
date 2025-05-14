#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct State {
    int car1, car2, distance;
    State() {}
    State(int c1, int c2, int d) : car1(c1), car2(c2), distance(d) {}
};

int n, w, dp[1002][1002];
pair<int, int> from[1002][1002];
vector<pair<int, int>> positions;

int dis(int i1, int i2) {
    auto p1 = positions[i1];
    auto p2 = positions[i2];
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void bfs() {
    State initialState(0, 1, 0);
    queue<State> q;
    dp[0][1] = 0;
    q.emplace(0, 1, 0);

    while (q.size()) {
        int car1 = q.front().car1;
        int car2 = q.front().car2;
        int d = q.front(). distance;
        q.pop();
        
        int cur = max(car1, car2) + 1;
        if (cur == w + 2) continue;

        // car1 -> cur
        int dis1 = dis(cur, car1);
        if (d + dis1 < dp[cur][car2]) {
            dp[cur][car2] = d + dis1;
            q.emplace(cur, car2, dp[cur][car2]);
            from[cur][car2] = {car1, car2};
        }

        // car2 -> cur
        int dis2 = dis(cur, car2);
        if (d + dis2 < dp[car1][cur]) {
            dp[car1][cur] = d + dis2;
            q.emplace(car1, cur, dp[car1][cur]);
            from[car1][cur] = {car1, car2};
        }
    }
}

void printOrder() {
    int minCost = 1e9;
    pair<int, int> lastState;
    for (int i = 0; i <= w + 1; ++i) {
        for (int j = 0; j <= w + 1; ++j) {
            if (max(i, j) == w +1 && dp[i][j] < minCost) {
                minCost = dp[i][j];
                lastState = {i, j};
            }
        }
    }
    cout << minCost << '\n';

    vector<int> order;
    auto curState = lastState;
    while (curState.first != 0 || curState.second != 1) {
        if (curState.first > curState.second) order.push_back(1);
        else order.push_back(2);

        curState = from[curState.first][curState.second];
    }
    reverse(order.begin(), order.end());
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

    fill(&dp[0][0], &dp[0][0] + 1002 * 1002, 1e9);
    bfs();
    printOrder();
}