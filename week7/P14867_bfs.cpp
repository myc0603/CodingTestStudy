#include <iostream>
#include <queue>
#include <vector>
// #include <map>
#include <unordered_map>
using namespace std;

int capA, capB, endA, endB;
// int visited[1002][1002];
// map<pair<int, int>, int> map_visited;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &v) const {
        auto h1 = std::hash<T1>{}(v.first);
        auto h2 = std::hash<T2>{}(v.second);
        return h1 ^ h2;
    }
};

unordered_map<pair<int, int>, int, pair_hash> map_visited;

vector<pair<int, int>> nextAmounts(int curA, int curB) {
    vector<pair<int, int>> v;
    if (curA != 0) v.push_back( {0, curB} );
    if (curB != 0) v.push_back( {curA, 0} );
    if (curA != capA) v.push_back( {capA, curB} );
    if (curB != capB) v.push_back( {curA, capB} );
    if (curA != 0 && curB != capB) {
        if (curA > capB - curB) v.push_back( {curA - (capB - curB), capB} );
        else v.push_back( {0, curB + curA} );
    }
    if (curB != 0 && curA != capA) {
        if (curB > capA - curA) v.push_back( {capA, curB - (capA - curA)} );
        else v.push_back( {curA + curB, 0} );
    }
    return v;
}

int bfs() {
    queue<pair<int, int>> q;
    q.push( {0, 0} );
    // visited[0][0] = 1;
    map_visited.insert( {{0, 0}, 1} );

    while (q.size()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        if (a == endA && b == endB) {
            // return visited[endA][endB] - 1;
            return map_visited[{endA, endB}] - 1;
        }

        auto nextABs = nextAmounts(a, b);
        for (auto p : nextABs) {
            // if (visited[p.first][p.second]) continue;
            if (map_visited.find({p.first, p.second}) != map_visited.end()) continue;
            q.push(p);
            // visited[p.first][p.second] = visited[a][b] + 1;
            map_visited[{p.first, p.second}] = map_visited[{a, b}] + 1;
        }
    }
    return -1;
}

int main() {
    cin >> capA >> capB >> endA >> endB;
    cout << bfs();
}