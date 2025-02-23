#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1004];
int visited[1004];

void postOrder(int here) {

    // if (visited[here] == 0) { // 이 조건이 필요한가?? ㄴㄴ

        for (int there : adj[here]) {
            postOrder(there);
        }
    
        visited[here] = 1;
        cout << here << ' ';
    // }
}

void preOrder(int here) {
    visited[here] = 1;
    cout << here << ' ';

    for (int there : adj[here]) {
        preOrder(there);
    }
}

void inOrder(int here) {
    // if (visited[here] == 0) {
        if (adj[here].size() == 0) {
            visited[here] = 1;
            cout << here << ' ';
        } else {
            inOrder(adj[here][0]);

            visited[here] = 1;
            cout << here << ' ';

            if (adj[here].size() == 2) inOrder(adj[here][1]);
        }
    // }
}

int main() {
    
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);

    int root = 1;

    cout << "\ntree traversal: postOrder \n"; // 4 5 2 3 1
    postOrder(root); memset(visited, 0, sizeof(visited));

    cout << "\ntree traversal: preOrder \n"; // 1 2 4 5 3
    preOrder(root); memset(visited, 0, sizeof(visited));

    cout << "\ntree traversal: inOrder \n"; // 4 2 5 1 3
    inOrder(root);

    return 0;
}