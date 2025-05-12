#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const string ENJOY = "Enjoy other party\n", STAY = "Stay here\n";
int n, m, a[502][502], minTime[502][502], dis[502];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push( {0, start} );

    while (pq.size()) {
        int curCost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (curCost > dis[cur]) continue;

        for (int next = 1; next <= n; ++next) {
            if (next == start || next == cur) continue;
            int nextCost = curCost + a[cur][next];
            if (nextCost < dis[next]) {
                pq.push( {nextCost, next} );
                dis[next] = nextCost;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        minTime[start][i] = dis[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        fill(dis, dis + 502, 1e9);
        // memset(dis, 0, sizeof(dis));
        dijkstra(i);
    }

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (minTime[a][b] <= c) cout << ENJOY;
        else cout << STAY;
    }
}