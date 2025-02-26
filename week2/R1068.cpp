#include <bits/stdc++.h>
using namespace std;

int a[50];

void printAdj(vector<int> adj[], int n) {
    cout << "print adj[n]\n";
    for (int i = 0; i < n; i++) {
        for (int num : adj[i]) {
            cout << num << ' ';
        }
        cout << '\n';
    }
}

int bfs(int root, vector<int> adj[], int delNode) {

    if (delNode == root) {
        return 0;
    }

    // // adj[a[delNode]] 에서 delNode 찾아서 삭제
    // vector<int> v = adj[a[delNode]];
    vector<int> &v = adj[a[delNode]];
    v.erase(remove(v.begin(), v.end(), delNode), v.end());


    int cnt = 0;

    queue<int> q;
    q.push(root);

    while (q.size()) {
        int u = q.front();
        q.pop();

        if (adj[u].size() == 0) {
            cnt++;
        }

        for (int v : adj[u]) {
            q.push(v);
        }
    }

    return cnt;
}

int main() {
    // input
    // initialize the adj list, find root
    int n; cin >> n;

    vector<int> adj[n];
    int root;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == -1) {
            root = i;
            continue;
        }
        adj[a[i]].push_back(i);
    }

    // delete node
    int delNode;
    cin >> delNode;

    cout << bfs(root, adj, delNode) << '\n';
}