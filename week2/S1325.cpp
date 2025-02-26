#include <bits/stdc++.h>
using namespace std;

int bfs(vector<int> adj[], int start, bool visited[]) {
    // cout << "\ncall bfs, start: " << start << '\n';
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    int cnt = 0;

    while (q.size()) {
        int u = q.front(); q.pop();
        // cout << "  visit, u: " << u << '\n';
        cnt++;

        for (int v : adj[u]) {
            if (visited[v] == 0) {
                // cout << "  push to q, v: " << v << '\n';
                q.push(v);
                visited[v] = 1;
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    int trusted[n+1] = {};
    int max = -1;
    for (int i = 1; i <= n; i++) {
        bool visited[n+1] = {};
        trusted[i] = bfs(adj, i, visited);
        max = max > trusted[i] ? max : trusted[i];
    }

    // check trusted, max
    for (int i = 1; i <= n; i++) {
        cout << trusted[i] << ' ';
    }
    cout << '\n';
    cout << "max: " << max << '\n';

    string ans;
    for (int i = 1; i <= n; i++) {
        if (trusted[i] == max) {
            ans += to_string(i) + ' ';
        }
    }
    cout << ans;
}