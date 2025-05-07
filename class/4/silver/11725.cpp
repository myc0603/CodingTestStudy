#include <iostream>
#include <vector>
using namespace std;

int n, parents[100003], visited[100003];
vector<int> adj[100003];

void dfs(int here) {
    visited[here] = 1;

    for (int there : adj[here]) {
        if (visited[there]) continue;
        parents[there] = here;
        dfs(there);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    for (int i = 2;  i <= n; ++i) cout << parents[i] << '\n';
}