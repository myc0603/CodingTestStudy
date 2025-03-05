#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1024]; // 1 ~ 1023
int buildingOrder[1024], buildingNum[1024];
int visited[1024];
int idx = 1;

void makeTree(int nodeCnt) {

    for (int i = 1; i <= nodeCnt/2; i++) {
        vector<int> v;
        v.push_back(2 * i);
        v.push_back(2 * i + 1);
        adj[i] = v;
    }
}

void bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    
    int temp = 2;
    string ans;
    while (q.size()) {
        int here = q.front(); q.pop();
        if (here % temp == 0) {
            ans += '\n';
            temp *= 2;
        }
        ans += to_string(buildingNum[here]) + ' ';

        for (int there : adj[here]) {
            if (!visited[there]) {
                q.push(there);
                visited[there] = 1;
            }
        }
    }
    cout << ans;
}

void inOrder(int here) {
    
    if (adj[here].empty()) {
        // here 방문로직
        buildingNum[here] = buildingOrder[idx++];
        return;
    }

    inOrder(adj[here][0]);
    // here 방문로직
    buildingNum[here] = buildingOrder[idx++];
    inOrder(adj[here][1]);
}

int main() {
    int k; cin >> k;
    int nodeCnt = pow(2, k) - 1;
    for (int i = 1; i <= nodeCnt; i++) {
        int num; cin >> num;
        buildingOrder[i] = num;
    }
    makeTree(nodeCnt);

    inOrder(1);
    bfs();

    
}