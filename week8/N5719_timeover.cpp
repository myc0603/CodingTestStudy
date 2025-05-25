#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
int n, m, s, d, a[502][502], dis[502], pre[502];

void dijkstra() {
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
            if (nextCost < dis[next]) {
                pq.push( {nextCost, next} );
                dis[next] = nextCost;
                pre[next] = cur;
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

        fill(pre, pre + 502, -1);
        dijkstra();

        int minDis = dis[d];

        for (int curMin = dis[d]; curMin == minDis; curMin = dis[d]) {
            int cur = d;
            while (pre[cur] != -1) {
                a[pre[cur]][cur] = INF;
                cur = pre[cur];
            }
            dijkstra();
        }

        dijkstra();
        if (dis[d] >= INF) cout << -1 << '\n';
        else cout << dis[d] << '\n';
    }
}
/*
시간 초과일 뿐 아니라 답도 틀림
반례:
4 5
0 2
0 1 1
0 3 5
1 2 2
1 3 1
3 2 1
0 0

답: -1, 오답 출력: 6

한 번 dijkstra 돌리고 최단 경로 상의 간선들을 모두 INF로 만들어버리면
원래 최단경로였던 다른 경로도 찾지 못함
그래서 모든 최단경로 상의 간선들을 INF로 만들지 못함
*/