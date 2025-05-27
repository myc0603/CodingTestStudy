#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100002;
int n, m, x, visited[MAX], visited_id = 1;
vector<int> adj[2][MAX];

int count(int upper) {
    int cnt = 0;
    queue<int> q;
    q.push(x);
    visited[x] = visited_id;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cnt++;
        for (int v : adj[upper][cur]) {
            if (visited[v] == visited_id) continue;
            q.push(v);
            visited[v] = visited_id;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[0][a].push_back(b);
        adj[1][b].push_back(a);
    }

    int lowerCnt = count(0);
    ++visited_id; // timestamp 방식
    // fill(visited, visited + MAX, 0);
    int upperCnt = count(1);

    cout << upperCnt << ' ' << n - lowerCnt + 1;
}