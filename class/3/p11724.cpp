#include <iostream>
#include <vector>
using namespace std;

int n, m, visited[1006];
vector<int> adj[1006];

void dfs(int here) {
    visited[here] = 1;

    for (int there : adj[here]) {
        if (visited[there]) continue;
        dfs(there);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        cnt++;
        dfs(i);
    }

    cout << cnt;
}