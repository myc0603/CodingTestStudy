#include <iostream>
#include <queue>
#include <unordered_set>
#include <cassert>
using namespace std;

struct Edge {
    int weight, from, to;
    Edge() {}
    Edge(int w, int f, int t) : weight(w), from(f), to(t) {}
};

struct cmp {
    bool operator()(const Edge &e1, const Edge &e2) {
        return e1.weight > e2.weight;
    }
};

int v, e;
vector<pair<int, int>> adj[10003];
unordered_set<int> tree;
priority_queue<Edge, vector<Edge>, cmp> edges;

int buildTree() {
    int totalWeight = 0;

    tree.insert(1);
    for (const auto &p : adj[1]) {
        edges.emplace(p.second, 1, p.first);
    }

    while (tree.size() < v) {
        assert(edges.size() != 0);
        auto edge = edges.top();
        edges.pop();
        if (tree.count(edge.to) != 0) continue;

        tree.insert(edge.to);
        totalWeight += edge.weight;
        for (const auto &p : adj[edge.to]) {
            // p.first가 tree 외부 정점인 경우에 edge 추가
            if (tree.count(p.first) == 0) {
                edges.emplace(p.second, edge.to, p.first);
            }
        }
    }

    return totalWeight;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;
    for (int i = 0; i < e; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back( {b, c} );
        adj[b].push_back( {a, c} );
    }


    cout << buildTree();
}