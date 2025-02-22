#include <bits/stdc++.h>
using namespace std;

const int n = 6;
vector<int> adj[n];
bool visited[n];
void dfsV1(int u) {
    visited[u] = 1;
    cout << u << '\n';
    for (int v : adj[u]) {
        if (visited[v] == false)
            dfsV1(v);
    }
    cout << u << ": return\n";
}

void dfsV2(int u) {
    if (visited[u]) return;
    visited[u] = true;
    cout << u << '\n';
    for (int v : adj[u]) {
        dfsV1(v);
    }
    cout << u << ": return\n";
}

int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);
    adj[4].push_back(2);

    // dfsV1(1);
    dfsV2(1);
}