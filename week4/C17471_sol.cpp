#include <bits/stdc++.h>
using namespace std;

int n, populations[11], zones[11], visited[11];
vector<int> adj[11];

/**
 * @return 연결된 노드 수, 연결된 노드의 인구수
 */
pair<int, int> dfs(int here, int zone) {
    visited[here] = 1;

    pair<int, int> result = {1, populations[here]};

    for (int there : adj[here]) {
        if (!visited[there] && zones[there] == zone) {
            // dfs
            pair<int, int> p = dfs(there, zone);
            result.first += p.first;
            result.second += p.second;
        }
    }

    return result;
}

int main() {
    cin >> n;
    for (int node = 1; node <= n; node++) {
        cin >> populations[node];
    }
    for (int node = 1; node <= n; node++) {
        int cnt; cin >> cnt;
        while (cnt--) {
            int temp; cin >> temp;
            adj[node].push_back(temp);
        }
    }

    int ans = 1e9;
    int casesCnt = 1 << n;
    for (int c = 1; c < casesCnt - 1; c++) {
        memset(zones, 0, sizeof(zones));
        memset(visited, 0, sizeof(visited));

        int zone0StartNode = -1;
        int zone1StartNode = -1;
        for (int node = 1; node <= n; node++) {
            if (c & (1 << (node-1))) {
                zones[node] = 1;
                zone1StartNode = node;
            } else zone0StartNode = node;
        }

        pair<int, int> zone0Info = dfs(zone0StartNode, 0);
        pair<int, int> zone1Info = dfs(zone1StartNode, 1);
        if (zone0Info.first + zone1Info.first == n) {
            ans = min(ans, abs(zone0Info.second - zone1Info.second));
        }
    }

    cout << (ans == 1e9 ? -1 : ans) << '\n';
}