#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, k, s, visited[402];
vector<int> adj[402];

bool canGo(int s, int e) {
    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while (q.size()) {
        int cur = q.front();
        q.pop();

        for (int nxt : adj[cur]) {
            if (visited[nxt]) continue;
            if (nxt == e) return true;
            q.push(nxt);
            visited[nxt] = 1;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    cin >> s;
    while (s--) {
        int a, b;
        cin >> a >> b;
        memset(visited, 0, sizeof(visited));
        if (canGo(a, b)) {
            cout << -1 << '\n';
            continue;
        }
        memset(visited, 0, sizeof(visited));
        if (canGo(b, a)) {
            cout << 1 << '\n';
            continue;
        }
        cout << 0 << '\n';
    }
}