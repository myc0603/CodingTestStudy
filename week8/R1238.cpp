#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
int n, m, x, dis[2][1002];
vector<pair<int, int>> a[2][1002];

void dijkstra(int isReturn) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push( {0, x} );
    dis[isReturn][x] = 0;

    while (pq.size()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cost > dis[isReturn][cur]) continue;

        for (auto p : a[isReturn][cur]) {
            int nextCost = cost + p.first;
            int nextPos = p.second;
            if (dis[isReturn][nextPos] > nextCost) {
                pq.push( {nextCost, nextPos} );
                dis[isReturn][nextPos] = nextCost;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x;
    for (int i = 0; i < m; ++i) {
        int s, e, t;
        cin >> s >> e >> t;
        a[0][s].push_back( {t, e} );
        a[1][e].push_back( {t, s} );
    }

    fill(&dis[0][0], &dis[0][0] + 2 * 1002, INF);
    dijkstra(0);
    dijkstra(1);

    int maxTime = 0;
    for (int i = 1; i <= n; ++i) {
        // if (i == x) continue;
        maxTime = max(maxTime, dis[0][i] + dis[1][i]);
    }
    cout << maxTime;
}