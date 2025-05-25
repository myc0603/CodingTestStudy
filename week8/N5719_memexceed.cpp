#include <iostream>
// #include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
int n, m, s, d, a[502][502], dis[502];
vector<vector<int>> paths[502];

void dijkstra(bool trace) {
    fill(dis, dis + 502, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push( {0, s} );
    dis[s] = 0;
    vector<int> v = {s};
    // paths[s].push_back(v);
    paths[s].emplace_back(v);

    while (pq.size()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cost > dis[cur]) continue;

        for (int next = 0; next < n; ++next) {
            if (next == cur) continue;
            int nextCost = cost + a[cur][next];
            if (trace && nextCost == dis[next]) {
                for (auto v : paths[cur]) {
                    v.push_back(next);
                    paths[next].emplace_back(v);
                }
            } else if (nextCost < dis[next]) {
                if (trace) {
                    paths[next] = paths[cur];
                    for (auto &v : paths[next]) v.push_back(next);
                }
                
                pq.push( {nextCost, next} );
                dis[next] = nextCost;
            }
        }
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

        for (int i = 0; i < 502; ++i) {
            for (auto &v : paths) v.clear();
        }

        dijkstra(true);
        for (const auto &v : paths[d]) {
            for (int i = 0; i < v.size() - 1; ++i) {
                a[v[i]][v[i+1]] = INF;
            }
        }

        dijkstra(false);
        if (dis[d] >= INF) cout << -1 << '\n';
        else cout << dis[d] << '\n';
    }
}