#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const string ENJOY = "Enjoy other party\n", STAY = "Stay here\n";
int n, m, a[502][502], minTime[502][502], dis[502];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    
    while (q.size()) {
        int cur = q.front();
        q.pop();

        for (int next = 1; next <= n; ++next) {
            if (next == start || next == cur) continue;
            if (dis[next] == 0 || dis[next] > dis[cur] + a[cur][next]) {
                dis[next] = dis[cur] + a[cur][next];
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        minTime[start][i] = dis[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        memset(dis, 0, sizeof(dis));
        bfs(i);
    }

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (minTime[a][b] <= c) cout << ENJOY;
        else cout << STAY;
    }
}