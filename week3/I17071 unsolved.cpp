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

    int movingDistance = 1;
    int broPosition = k;
    int sec = 1;
    while (broPosition <= MAX) {
        // cout << broPosition << ": " << sec << '\n';
        broVisited[broPosition] = sec;
        broPosition += sec++;
    }

    queue<int> q;
    q.push(n);
    visited[n] = 1;

    // bool flag = false;
    int ans = -1;
    while (q.size()) {
        int cur = q.front(); q.pop();

        if (visited[cur] == broVisited[cur]) {
            // flag = true;
            ans = visited[cur] - 1;
            // cout << "find! visited[cur]: " << visited[cur] << ", ans: " << ans << '\n';
            break;
        }
        
        for (int next : {cur + 1, cur - 1, cur * 2}) {
            if (next < 0 || next > MAX) continue;
            if (!visited[next]) {
                q.push(next);
                visited[next] = visited[cur] + 1;
            }
        }
    }

    // printVisited();
    
    cout << ans << '\n';
    // if (!flag) {
    //     cout << "cannot find\n";
    // }
}