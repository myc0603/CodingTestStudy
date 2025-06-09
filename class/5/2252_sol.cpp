#include <iostream>
#include <queue>
using namespace std;

int n, m, indegree[32003];
vector<int> adj[32003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        ++indegree[b];
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        cout << cur << ' ';

        for (int x : adj[cur]) {
            --indegree[x];
            if (indegree[x] == 0) q.push(x);
        }
    }
}