#include <iostream>
#include <queue>
using namespace std;

int t, n, k, times[1002], w, dp[1002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        fill(dp, dp + 1002, 0);
        vector<int> adj[n + 1];
        vector<int> indegree(n + 1), times(n + 1);
        for (int i = 1; i <= n; ++i) cin >> times[i];
        for (int i = 0; i < k; ++i) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            ++indegree[y];
        }
        cin >> w;

        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
                dp[i] = times[i];
            }
        }

        while (q.size()) {
            int cur = q.front();
            q.pop();

            for (int x : adj[cur]) {
                dp[x] = max(dp[x], dp[cur] + times[x]);
                --indegree[x];
                if (indegree[x] == 0) {
                    q.push(x);
                }
            }
        }

        cout << dp[w] << '\n';
    }
}