#include <iostream>
#include <queue>
using namespace std;

const int INF = 1e9;
int n, m, s, d, a[502][502], dis[502], visited[502];
vector<int> parents[502];

void dijkstra(bool trace) {
    fill(dis, dis + 502, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push( {0, s} );
    dis[s] = 0;

    while (pq.size()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cost > dis[cur]) continue;

        for (int next = 0; next < n; ++next) {
            if (next == cur) continue;
            int nextCost = cost + a[cur][next];
            if (nextCost == dis[next]) {
                parents[next].push_back(cur);
            } else if (nextCost < dis[next]) {
                parents[next] = vector<int>(1, cur);
                pq.push( {nextCost, next} );
                dis[next] = nextCost;
            }
        }
    }
}

void dfs(int cur) {
    visited[cur] = 1;
    for (int par : parents[cur]) {
        a[par][cur] = INF;
        if (!visited[par]) dfs(par);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        fill(&a[0][0], &a[0][0] + 502 * 502, INF);
        cin >> s >> d; // s -> d
        for (int i = 0; i < m; ++i) {
            int u, v, p;
            cin >> u >> v >> p;
            a[u][v] = p;
        }

        for (auto &v : parents) v.clear();

        dijkstra(true);
        fill(visited, visited + 502, 0);
        dfs(d);

        dijkstra(false);
        if (dis[d] >= INF) cout << -1 << '\n';
        else cout << dis[d] << '\n';
    }
}