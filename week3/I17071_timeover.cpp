#include <bits/stdc++.h>
using namespace std;

const int MAX = 500000;
int visited[MAX+1], broVisited[MAX+1];

void printVisited() {
    for (int i = 0; i < 40; i++) {
        cout << i << ": " << visited[i] << ' ' << broVisited[i] << '\n';
    }
}

int main() {
    int n, k; cin >> n >> k;

    int broPosition = k;
    int sec = 0;
    while (broPosition <= MAX) {
        // cout << broPosition << ": " << sec << '\n';
        broVisited[broPosition] = sec + 1;
        broPosition += ++sec;
    }

    cout << "broVisited[10]: " << broVisited[10] << '\n'; // 1
    cout << "broVisited[11]: " << broVisited[11] << '\n'; // 2
    cout << "broVisited[13]: " << broVisited[13] << '\n'; // 3
    cout << "broVisited[16]: " << broVisited[16] << '\n'; // 4
    cout << "broVisited[20]: " << broVisited[20] << '\n'; // 5
    cout << "broVisited[25]: " << broVisited[25] << '\n'; // 6
    cout << "broVisited[31]: " << broVisited[31] << '\n'; // 7

    queue<int> q;
    q.push(n);
    visited[n] = 1;

    int ans = -1;
    while (q.size()) {
        int cur = q.front(); q.pop();

        // if (visited[cur] > movingCount) break;
        if (visited[cur] == broVisited[cur]) {
            ans = visited[cur] - 1;
            // cout << "find! visited[cur]: " << visited[cur] << ", ans: " << ans << '\n';
            break;
        }
        
        for (int next : {cur + 1, cur - 1, cur * 2}) {
            if (next < 0 || next > MAX) continue;
            if (visited[cur] >= sec + 1) continue;
            //
            if (visited[cur] >= 7) continue;
            //
            if (!visited[next] || visited[next] < visited[cur] + 1) {
                q.push(next);
                visited[next] = visited[cur] + 1;
                cout << "visited[" << next << "]: " << visited[next] << '\n';
            }
        }
    }

    printVisited();
    
    cout << ans << '\n';
}