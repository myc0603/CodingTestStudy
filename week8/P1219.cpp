#include <iostream>
#include <queue>
using namespace std;

struct Edge {
    int from, to, cost;
    Edge(int f, int t, int c) : from(f), to(t), cost(c) {}
};
const int INF = 1e9;
int n, s, e, m, earn[52], visited[52];
long long dis[52];
vector<int> neg_cycle;
vector<pair<int, int>> adj[52];

bool bellmanFord() {
    dis[s] = -earn[s];
    for (int j = 1; j <= n; ++j) {
        for (int i = 0; i < n; ++i) {
            for (const auto &p : adj[i]) {
                if (dis[i] != INF && dis[i] + p.second < dis[p.first]) {
                    dis[p.first] = dis[i] + p.second;
                    if (j == n) neg_cycle.push_back(p.first);
                }
            }
        }
    }
    return neg_cycle.empty();
}

bool canGoFromNegativeCycleToEnd() {
    queue<int> q;
    for (auto v : neg_cycle) {
        // if (v == e) return true; 안 해도 됨
        q.push(v);
        visited[v] = 1;
    }

    while (q.size()) {
        int cur = q.front();
        q.pop();

        for (auto p : adj[cur]) {
            int next = p.first;
            if (next == e) return true;
            if (visited[next]) continue;
            visited[next] = 1;
            q.push(next);
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s >> e >> m;
    for (int i = 0; i < m; ++i) {
        int f, t, c;
        cin >> f >> t >> c;
        adj[f].push_back( {t, c} );
    }
    for (int i = 0; i < n; ++i) cin >> earn[i];
    for (int from = 0; from < n; ++from) {
        for (auto &p : adj[from]) { // to, cost
            p.second -= earn[p.first];
        }
    }

    fill(dis, dis + 52, INF);
    bool result = bellmanFord();
    if (dis[e] == INF) cout << "gg";
    else if (!result && canGoFromNegativeCycleToEnd()) cout << "Gee";
    else cout << -dis[e];
}