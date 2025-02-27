#include <bits/stdc++.h>
using namespace std;

int dfs(int here, vector<int> adj[], int delNode) {

    int cnt = 0;

    for (int there : adj[here]) {
        if (there == delNode) {
            continue;
        }
        cnt += dfs(there, adj, delNode);
    }

    return cnt == 0 ? 1 : cnt;
}

int main() {
    // input
    // initialize the adj list, find root
    int n; cin >> n;

    vector<int> adj[n];
    int root;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num == -1) {
            root = i;
            continue;
        }
        adj[num].push_back(i);
    }

    // to be deleted node
    int delNode;
    cin >> delNode;

    cout << (delNode == root ? 0 : dfs(root, adj, delNode)) << '\n';
}