#include <iostream>
using namespace std;

const int INF = 1e9;
int n, m, dis[202][202], pre[202][202];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill(&dis[0][0], &dis[0][0] + 202 * 202, INF);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        dis[u][v] = d;
        dis[v][u] = d;
        pre[u][v] = v;
        pre[v][u] = u;
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j) continue;
                if (dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    pre[i][j] = pre[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) cout << "- ";
            else cout << pre[i][j] << ' ';
        }
        cout << '\n';
    }
}