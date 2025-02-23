#include <bits/stdc++.h>
using namespace std;

const int n = 6;
vector<int> adj[n];
bool visited[n];
queue<int> q;
void bfs(int root) {
    visited[root] = true;
    q.push(root);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // 방문시 필요한 로직
        // visited[u] = true;
        cout << "visit: " << u << '\n';

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void bfs2(int u) {
    visited[u] = true;
    q.push(u);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << "visit: " << u << '\n';
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);
    adj[3].push_back(6);
    adj[3].push_back(7);
    adj[3].push_back(8);
    adj[3].push_back(9);
    adj[4].push_back(10);

    // bfs(1);
    bfs2(1);
}