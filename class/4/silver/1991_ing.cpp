#include <iostream>
#include <vector>
using namespace std;

const char BASE_CHAR = 'A' - 1;
int n, visited[30];
vector<int> adj[30];

void preorder(int cur) {
    visited[cur];
    cout << BASE_CHAR + (char) cur;

    int left = adj[cur][0];
    if (left) preorder(left);

    int right = adj[cur][1];
    if (right) preorder(right);
}

void inorder(int cur) {
    int left = adj[cur][0];
    if (left) preorder(left);
    
    visited[cur];
    cout << BASE_CHAR + (char) cur;

    int right = adj[cur][1];
    if (right) preorder(right);
}

void postorder(int cur) {
    int left = adj[cur][0];
    if (left) preorder(left);

    int right = adj[cur][1];
    if (right) preorder(right);

    visited[cur];
    cout << BASE_CHAR + (char) cur;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        adj[i].resize(2);
    }
    for (int i = 0; i < n; ++i) {
        char me, left, right;
        cin >> me >> left >> right;
        if (left != '.') adj[me-BASE_CHAR][0] = left;
        if (right != '.') adj[me-BASE_CHAR][1] = right;
    }

    preorder(1);
    cout << '\n';

    fill(visited, visited + n, 0);
    inorder(1);
    cout << '\n';

    fill(visited, visited + n, 0);
    postorder(1);
}