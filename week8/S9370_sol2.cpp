#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int n, m, t, s, g, h, dis[4][2002];
vector<pair<int, int>> adj[2002];
vector<int> cands;

void dijkstra(int start) {
    int idx = start == s ? 0 : (start == g ? 1 : 2);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push( {0, start} );
    dis[idx][start] = 0;

    while (pq.size()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cost > dis[idx][cur]) continue;

        for (const auto &p : adj[cur]) {
            int nextCost = cost + p.first;
            int next = p.second;
            if (dis[idx][next] > nextCost) {
                pq.push( {nextCost, next} );
                dis[idx][next] = nextCost;
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        cin >> n >> m >> t >> s >> g >> h;

        for (int i = 1; i <= n; ++i) adj[i].clear();
        for (int i = 0; i < m; ++i) {
            int a, b, d;
            cin >> a >> b >> d;
            adj[a].push_back( {d, b} );
            adj[b].push_back( {d, a} );
        }

        cands.clear();
        for (int i = 0; i < t; ++i) {
            int c; cin >> c;
            cands.push_back(c);
        }
        sort(cands.begin(), cands.end());

        fill(&dis[0][0], &dis[0][0] + 4 * 2002, INF);
        dijkstra(s);
        dijkstra(g);
        dijkstra(h);

        int gtoh;
        for (const auto &p : adj[g]) {
            if (p.second == h) {
                gtoh = p.first;
                break;
            }
        }

        // dis[0][i]: s->i, dis[1][i]: g->i, dis[2][i]: h->i
        for (int cand : cands) {
            if ((dis[0][cand] == dis[0][h] + gtoh + dis[1][cand]) ||
                (dis[0][cand] == dis[0][g] + gtoh + dis[2][cand])) cout << cand << ' ';
        }
        cout << '\n';
    }
}