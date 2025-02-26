#include <bits/stdc++.h>
using namespace std;

const int n = 10;
vector<int> adj[n];
bool visited[n];

void bfs(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {

        // visit logic
        int u = q.front();
        cout << "visit: " << u << '\n';
        q.pop();
        
        for (int v : adj[u]) {
            if (visited[v] == 0) {
                cout << "q.push: " << v << '\n';
                q.push(v);
                visited[v] = 1;
                // visited[v] = visited[u] + 1;
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

    bfs(1);
}