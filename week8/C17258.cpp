#include <iostream>
#include <cstring>
using namespace std;

int n, m, k, t, people[302], dp[302][302];

int dfs(int curTime, int cnt) {
    if (cnt > k) return 0;
    if (curTime >= n + 1) return 0;

    int &result = dp[curTime][cnt];
    if (result != -1) return result;

    int nextTime = -1;
    for (int i = curTime; i <= n + 1; ++i) {
        if (people[curTime] != people[i]) {
            nextTime = i;
            break;
        }
    }
    if (nextTime == -1) nextTime = n + 1;

    int add = t - people[curTime];
    if (add > 0) {
        result = max(dfs(nextTime, cnt), dfs(nextTime, cnt + add) + (nextTime - curTime));
    } else {
        result = dfs(nextTime, cnt) + nextTime - curTime;
    }
    return result;
}

int main() {
    cin >> n >> m >> k >> t;
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        for (int j = from; j < to; ++j) {
            ++people[j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << dfs(1, 0);
}