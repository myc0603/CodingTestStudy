#include <iostream>
#include <queue>
using namespace std;

int t, n, k, times[1002], w;

bool connected(vector<int> adj[], int start) {
    int visited[1002] = {};
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (q.size()) {
        int cur = q.front();
        q.pop();

        if (cur == w) return true;
        for (int x : adj[cur]) {
            if (visited[x]) continue;
            q.push(x);
            visited[x] = 1;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> times[i];
        vector<int> adj[1002];
        int indegree[1002] = {};
        for (int i = 0; i < k; ++i) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            ++indegree[y];
        }
        cin >> w;

        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (indegree[i] == 0 && connected(adj, i)) q.push(i);
        }

        bool last = false;
        int time = 0;
        while (q.size()) {
            int qsize = q.size();

            int temp = 0;
            for (int i = 0; i < qsize; ++i) {
                int cur = q.front();
                q.pop();

                if (cur == w) {
                    last = true;
                    temp = times[cur];
                    break;
                }

                temp = max(temp, times[cur]);
                for (int x : adj[cur]) {
                    --indegree[x];
                    if (indegree[x] == 0) q.push(x);
                }
            }
            // cout << "temp: " << temp << "\n";
            time += temp;
            if (last) break;
        }
        cout << time << '\n';
    }
}