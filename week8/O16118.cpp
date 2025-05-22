#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
int n, m, dis[2][2][4002]; // dis[0][0][i] : fox, dis[1][state][i] : wolf
vector<pair<int, int>> v[4002];

struct State {
    int cur, cost, coef;
    State() {}
    State(int _cur, int _cost, int _coef) : cur(_cur), cost(_cost), coef(_coef) {}

    bool operator>(const State &s) const {
        return cost > s.cost;
    }
};

void dijkstra(bool isWolf) {
    priority_queue<State, vector<State>, greater<State>> pq;

    pq.push( {1, 0, (isWolf ? 1 : 2)} );
    while (pq.size()) {
        int cur = pq.top().cur;
        int cost = pq.top().cost;
        int coef = pq.top().coef;
        int curState = coef == 1 ? 1 : 0;
        pq.pop();

        if (cost > dis[isWolf][curState][cur]) continue;

        for (auto p : v[cur]) {
            int nextPos = p.first;
            int nextCost = cost + coef * p.second;
            int nextCoef = (isWolf ? (coef ^ 5) : coef);
            int nextState = nextCoef == 1 ? 1 : 0;
            if (dis[isWolf][nextState][nextPos] > nextCost) {
                pq.push( {nextPos, nextCost, (isWolf ? (coef ^ 5) : coef)} );
                dis[isWolf][nextState][nextPos] = nextCost;
            }
        }
    }
}

// 1-based index
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        v[a].push_back( {b, d} );
        v[b].push_back( {a, d} );
    }

    fill(&dis[0][0][0], &dis[0][0][0] + 2 * 2 * 4002, INF);
    dijkstra(false);
    dijkstra(true);

    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        int wolfMin = min(dis[1][0][i], dis[1][1][i]);
        if (dis[0][0][i] < wolfMin) ++cnt;
    }
    cout << cnt;
}