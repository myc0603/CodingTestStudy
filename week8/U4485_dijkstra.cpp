#include <iostream>
#include <queue>
using namespace std;

const int INF = 1e9, MAX = 127;
int n, a[MAX][MAX], dis[MAX][MAX];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push( {a[0][0], 0} );
    dis[0][0] = a[0][0];

    while (pq.size()) {
        int cost = pq.top().first;
        int y = pq.top().second / MAX;
        int x = pq.top().second % MAX;
        pq.pop();

        if (cost > dis[y][x]) continue;

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || n <= ny || nx < 0 || n <= nx) continue;
            int nextCost = cost + a[ny][nx];
            if (dis[ny][nx] > nextCost) {
                dis[ny][nx] = nextCost;
                pq.push( {nextCost, ny * MAX + nx} );
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i = 1;
    while (true) {
        cin >> n;
        if (n == 0) break;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        fill(&dis[0][0], &dis[0][0] + MAX * MAX, INF);
        dijkstra();
        cout << "Problem " << i++ << ": " << dis[n-1][n-1] << '\n';
    }
}