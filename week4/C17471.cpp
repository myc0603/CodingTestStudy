#include <bits/stdc++.h>
using namespace std;

int n, populations[11], visited[11];
vector<int> adj[11];

int getZone(int c, int node) {
    int nodeIdx = node - 1;
    if (c & (1 << nodeIdx)) {
        return 1;
    }
    return 0;
}

void dfs(int c, int here, int zone) {
    visited[here] = 1;

    for (int there : adj[here]) {
        if (!visited[there] && getZone(c, there) == zone) {
            dfs(c, there, zone);
        }
    }
}

bool validSeparation(int c) { // c: case
    int zoneCnt[2] = {};

    for (int node = 1; node <= n; node++) {
        if (!visited[node]) {
            int zone = getZone(c, node);
            zoneCnt[zone]++;

            dfs(c, node, zone);
        }
    }

    return zoneCnt[0] == 1 && zoneCnt[1] == 1;
}

int main() {
    cin >> n; // 구역의 개수 2 ~ 10
    for (int i = 1; i <= n; i++) { // 구역별 인구수
        cin >> populations[i];
    }
    for (int i = 1; i <= n; i++) { // 구역 지도 초기화
        int cnt; cin >> cnt;
        while (cnt--) {
            int num; cin >> num;
            adj[i].push_back(num);
        }        
    }
    
    int ans = 1000;
    bool separated = false;
    int cases = 1 << n;
    for (int c = 1; c < cases - 1; c++) { // c = 00....0, 11...1 인 경우 제외

        memset(visited, 0, sizeof(visited));
        if (validSeparation(c)) {
            cout << "valid separate! case: " << c << '\n';
            separated = true;

            int zonePopulations[2] = {};
            for (int node = 1; node <= n; node++) {
                zonePopulations[getZone(c, node)] += populations[node];
            }
            ans = min(ans, abs(zonePopulations[1] - zonePopulations[0]));
        }
    }

    cout << (separated ? ans : -1) << '\n';
}