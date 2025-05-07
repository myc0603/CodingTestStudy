#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v, visited[1005];
vector<int> a[1005];
string ans;

void dfs(int here) {
    visited[here] = 1;
    ans += to_string(here) + ' ';

    for (int there : a[here]) {
        if (!visited[there]) dfs(there);
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (q.size()) {
        int cur = q.front();
        q.pop();

        ans += to_string(cur) + ' ';

        for (int next : a[cur]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = 1;
            }
        }
    }
}

// 1-based index
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        a[v1].push_back(v2);
        a[v2].push_back(v1);
    }

    for (int i = 1; i <= n; i++) {
        sort(a[i].begin(), a[i].end());
    }

    dfs(v);
    fill(visited, visited + 1005, 0);
    ans += '\n';
    bfs(v);

    cout << ans;
}