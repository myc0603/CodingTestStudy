#include <bits/stdc++.h>
using namespace std;

void go(vector<int> adj[], int n, int from, bool visited[]) {
    cout << "call go(), current vertex: " << from << '\n';
    visited[from] = true;
    for (int i = 0; i < n; i++) {
        for (int v : adj[i]) {
            if (visited[v]) continue;
            cout << from << "->" << v << '\n';
            go(adj, n, v, visited);
        }
    }
}

int main() {
    // 사실상 행렬인데 데이터가 bool에서 int,노드의 번호로 바뀜
    vector<int> adj[10];
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);

    bool visited[10] = {};
    go(adj, 10, 1, visited);
}