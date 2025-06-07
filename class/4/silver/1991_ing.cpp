#include <iostream>
#include <vector>
using namespace std;

const char BASE_CHAR = 'A';
int n;
vector<int> adj[30];

void dfs();

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        adj[i].resize(2);
    }
    for (int i = 0; i < n; ++i) {
        char me, left, right;
        cin >> me >> left >> right;
        adj[me-BASE_CHAR][0] = left;
        adj[me-BASE_CHAR][1] = right;
    }
}