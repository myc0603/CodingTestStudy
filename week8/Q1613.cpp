#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cassert>
using namespace std;

const int SIZE = 402;
int n, k, s, visited[SIZE];
vector<int> adj[SIZE], greaterThan[SIZE];

bool contain(const vector<int> &v, int value) {
    for (int x : v) {
        if (x == value) return true;
    }
    return false;
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while (q.size()) {
        int cur = q.front();
        q.pop();

        for (int nxt : adj[cur]) {
            if (visited[nxt]) continue;
            q.push(nxt);
            visited[nxt] = 1;
            greaterThan[s].push_back(nxt);
        }
    }
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

    for (int i = 1; i <= n; ++i) {
        memset(visited, 0, sizeof(visited));
        bfs(i);
    }

    cin >> s;
    while (s--) {
        int a, b;
        cin >> a >> b;
        if (contain(greaterThan[a], b)) { // a < b
            cout << -1 << '\n';
        } else if (contain(greaterThan[b], a)) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}