#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, visited[32003];
vector<int> adj[32003], line;

void dfs(int cur) {
    visited[cur] = 1;
    line.push_back(cur);

    for (int next : adj[cur]) {
        if (visited[next]) continue;
        dfs(next);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (visited[i]) continue;
        dfs(i);
    }
    sort(line.begin(), line.end());

    for (int x : line) cout << x << ' ';
}