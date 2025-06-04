#include <iostream>
#include <queue>
using namespace std;

int n, m, visited[102];
vector<int> adj[102];

int dfs(int cur) {
    int cnt = 1;
    visited[cur] = 1;

    for (int next : adj[cur]) {
        if (visited[next]) continue;
        cnt += dfs(next);
    }
    return cnt;
}

int bfs() {
    int cnt = 0;
    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while (!q.empty()) {
        ++cnt;
        int cur = q.front();
        q.pop();

        for (int next : adj[cur]) {
            if (visited[next]) continue;
            q.push(next);
            visited[next] = 1;
        }
    }

    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << dfs(1) - 1;
    // cout << bfs() - 1;
}