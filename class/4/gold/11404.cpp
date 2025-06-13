#include <iostream>
using namespace std;
const int INF = 1e9;
int n, m, cost[102][102];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill(&cost[0][0], &cost[0][0] + 102 * 102, INF);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        cost[a][b] = min(cost[a][b], c);
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << (cost[i][j] >= INF || i == j ? 0 : cost[i][j]) << ' ';
        }
        cout << '\n';
    }
}