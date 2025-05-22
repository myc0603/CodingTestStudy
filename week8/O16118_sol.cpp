#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
int n, m, fox[4002], wolf[2][4002];
vector<pair<int, int>> v[4002];

struct State {
    int cur, cost;
    bool state;
    State() {}
    State(int _cur, int _cost, bool s) : cur(_cur), cost(_cost), state(s) {}

    bool operator>(const State &s) const {
        return cost > s.cost;
    }
};

void dijkstraForFox() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.push({0, 1});
    while (pq.size()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cost > fox[cur]) continue;

        for (auto p : v[cur]) {
            int nextPos = p.first;
            int nextCost = cost + 2 * p.second;
            if (fox[nextPos] > nextCost) {
                pq.push( {nextCost, nextPos} );
                fox[nextPos] = nextCost;
            }
        }
    }
}

void dijkstraForWolf() {
    priority_queue<State, vector<State>, greater<State>> pq;

    pq.push( {1, 0, 0} );
    while (pq.size()) {
        int cur = pq.top().cur;
        int cost = pq.top().cost;
        bool curState = pq.top().state;
        int coef = curState ? 4 : 1;
        pq.pop();

        if (cost > wolf[curState][cur]) continue;

        for (auto p : v[cur]) {
            int nextPos = p.first;
            int nextCost = cost + coef * p.second;
            bool nextState = curState ^ 1;
            if (wolf[nextState][nextPos] > nextCost) {
                pq.push( {nextPos, nextCost, nextState} );
                wolf[nextState][nextPos] = nextCost;
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

    fill(fox, fox + 4002, INF);
    fill(&wolf[0][0], &wolf[0][0] + 2 * 4002, INF);
    dijkstraForFox();
    dijkstraForWolf();

    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        int wolfMin = min(wolf[0][i], wolf[1][i]);
        if (fox[i] < wolfMin) ++cnt;
    }
    cout << cnt;
}