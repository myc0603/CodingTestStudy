#include <bits/stdc++.h>
using namespace std;

int visited[1000];
vector<int> tree[1000];

int dfs(int here) {
    visited[here] = 1;

    int cnt = 1;

    for (int there : tree[here]) {
        if (!visited[there]) {
            cnt += dfs(there);
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    int t; cin >> t;

    string ans;
    while (t--) {
        int nodes; int edges;
        cin >> nodes >> edges;

        for (int i = 0; i < edges; i++) {
            int a, b; cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        if (nodes - 1 != edges) {
            ans += "graph\n";
            continue;
        }
        int cnt = dfs(1);
        ans += cnt == nodes ? "tree\n" : "graph\n";
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < 1000; i++) {
            tree[i].clear();
        }
    }
    cout << ans;
}