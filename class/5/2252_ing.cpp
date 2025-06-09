#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, visited[32003], notStart[32003];
vector<int> adj[32003], line;

// void dfs(int cur) {
//     visited[cur] = 1;
//     line.push_back(cur);

//     for (int next : adj[cur]) {
//         if (visited[next]) continue;
//         dfs(next);
//     }
// }

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    
    while (q.size()) {
        int cur = q.front();
        q.pop();

        line.push_back(cur);

        for (int next : adj[cur]) {
            if (visited[next]) continue;
            q.push(next);
            visited[next] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        notStart[a] = 1;
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (notStart[i]) continue;
        if (visited[i]) continue;
        bfs(i);
    }
    reverse(line.begin(), line.end());

    for (int x : line) cout << x << ' ';
}