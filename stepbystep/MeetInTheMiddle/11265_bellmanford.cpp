#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Edge {
    int from, to, weight;
    Edge() {}
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

const int INF = 1e9;
const string ENJOY = "Enjoy other party\n", STAY = "Stay here\n";
vector<Edge> edges;
vector<int> minusCycle;
int n, m, a[502][502], minTime[502][502], dis[502];

void bellman_ford(int start) {

    dis[start] = 0;

    for (int i = 1; i <= n; ++i) {
        for (auto e : edges) {
            if (dis[e.from] != INF && dis[e.to] > dis[e.from] + e.weight) {
                if (i == n) minusCycle.push_back(e.to);
                dis[e.to] = dis[e.from] + e.weight;
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
    edges.reserve(n * n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int d; cin >> d;
            edges.emplace_back(i, j, d);
        }
    }

    for (int i = 1; i <= n; ++i) {
        fill(dis, dis + 502, INF);
        bellman_ford(i);
    }

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (minTime[a][b] <= c) cout << ENJOY;
        else cout << STAY;
    }
}