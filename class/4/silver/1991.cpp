#include <iostream>
#include <vector>
using namespace std;

const char BASE_CHAR = 'A' - 1;
int n;
vector<int> adj[30];
vector<char> pre, in, post;

void preorder(int cur) {
    pre.push_back(BASE_CHAR + cur);

    int left = adj[cur][0];
    if (left) preorder(left);

    int right = adj[cur][1];
    if (right) preorder(right);
}

void inorder(int cur) {
    int left = adj[cur][0];
    if (left) inorder(left);
    
    in.push_back(BASE_CHAR + cur);

    int right = adj[cur][1];
    if (right) inorder(right);
}

void postorder(int cur) {
    int left = adj[cur][0];
    if (left) postorder(left);

    int right = adj[cur][1];
    if (right) postorder(right);

    post.push_back(BASE_CHAR + cur);
}

int main() {
    cin >> n;
    for (int i = 0; i <= n; ++i) adj[i].resize(2);
    for (int i = 0; i < n; ++i) {
        char me, left, right;
        cin >> me >> left >> right;
        if (left != '.') adj[me-BASE_CHAR][0] = left - BASE_CHAR;
        if (right != '.') adj[me-BASE_CHAR][1] = right - BASE_CHAR;
    }

    int start = 'A' - BASE_CHAR;
    preorder(start);
    inorder(start);
    postorder(start);

    for (char c : pre) cout << c; cout << '\n';
    for (char c : in) cout << c; cout << '\n';
    for (char c : post) cout << c;
}