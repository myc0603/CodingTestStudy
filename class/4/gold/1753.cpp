#include <iostream>
#include <queue>
using namespace std;

const int INF = 1e9;
int n, m, s, dis[20003];
vector<pair<int, int>> a[20003];

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push( {0, s} );
    dis[s] = 0;

    while (pq.size()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cost > dis[cur]) continue;

        for (const auto &p : a[cur]) {
            int nextCost = cost + p.second;
            int next = p.first;
            if (nextCost < dis[next]) {
                dis[next] = nextCost;
                pq.push( {nextCost, next} );
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back( {v, w} );
    }

    fill(dis, dis + 20003, INF);
    dijkstra();

    for (int i = 1; i <= n; ++i) {
        if (dis[i] >= INF) cout << "INF" << '\n';
        else cout << dis[i] << '\n';
    }
}