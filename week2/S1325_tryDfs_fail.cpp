#include <bits/stdc++.h>
using namespace std;

// int trusted[10001] = {};

void dfs(vector<int> adj[], int trusted[], int here, bool visited[]) {
    visited[here] = 1;

    if (adj[here].size() == 0) {
        trusted[here] = 1;
        cout << "trusted[" << here << "]: " << trusted[here] << '\n';
        return;
    }

    // 자기자신도 포함해야지~
    int sum = 1;
    for (int there : adj[here]) {
        if (visited[there] == 0) {
            cout << here << " -> " << there << '\n';
            dfs(adj, trusted, there, visited);
            sum += trusted[there];
        }
    }
    trusted[here] = max(sum, trusted[here]);
    cout << "trusted[" << here << "]: " << trusted[here] << '\n';
}

int bfs(vector<int> adj[], int start, bool visited[]) {
    queue<int> q;
    q.push(start);

    int cnt = -1;

    while (q.size()) {
        int u = q.front(); q.pop();
        cnt++;

        for (int v : adj[u]) {
            if (visited[v] == 0) {
                q.push(v);
                visited[v] = 1;
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    // check adj list.
    cout << "=========\n";
    for (int i = 1; i <= n; i++) {
        for (int num : adj[i]) {
            cout << num << ' ';
        }
        cout << '\n';
    }
    cout << "=========\n";
    
    int trusted[n+1] = {};
    bool visited[n+1] = {};
    // 1 ~ n까지 trusted가 업뎃 안된 애들 dfs돌렷!
    // for (int i = 1; i <= n; i++) {
    //     // if (trusted[i] == 0) {
    //         dfs(adj, trusted, i, visited);
    //         memset(visited, 0, sizeof(visited));
    //     // }
    // }

    for (int i = 1; i <= n; i++) {
        trusted[i] = bfs(adj, i, visited);
        memset(visited, 0, sizeof(visited));
    }

    // check trusted
    for (int num : trusted) {
        cout << num << ' ';
    }
    cout << '\n';

    // 이제 trusted에서 가장 큰 값을 가진 인덱스를 오름차순으로 출력
    int max = *max_element(trusted + 1, trusted + n + 1);
    string ans;
    for (int i = 1; i <= n; i++) {
        if (trusted[i] == max) {
            ans += to_string(i) + ' ';
        }
    }
    cout << ans;
}