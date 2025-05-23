#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int n, m, t, s, g, h, pre[2002], dis[2002];
vector<pair<int, int>> adj[2002];
vector<int> cands;

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push( {0, s} );

    while (pq.size()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cost > dis[cur]) continue;

        for (auto p : adj[cur]) {
            int nextCost = cost + p.first;
            int nxt = p.second;
            if (nxt == s) continue; // 이거만 하면 되나? 될 거 같긴 함
            if (dis[nxt] > nextCost) {
                dis[nxt] = nextCost;
                pq.push( {nextCost, nxt} );
                pre[nxt] = cur;
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
            d <<= 1;
            if ((a == g && b == h) || (a == h && b == g)) --d;
            adj[a].push_back( {d, b} );
            adj[b].push_back( {d, a} );
        }

        cands.clear();
        cands.resize(t);
        for (int i = 0; i < t; ++i) cin >> cands[i];
        sort(cands.begin(), cands.end());

        fill(pre, pre + 2002, 0);
        fill(dis, dis + 2002, INF);
        dijkstra();

        for (int cand : cands) {
            // int cur = cand;
            // while (pre[cur]) {
            //     if ((cur == g && pre[cur] == h) || (cur == h && pre[cur] == g)) {
            //         cout << cand << ' ';
            //     }
            //     cur = pre[cur];
            // }
            if (dis[cand] % 2) cout << cand << ' '; // 경로추적할 필요 없음
        }
        cout << '\n';
    }
}