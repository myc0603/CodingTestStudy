#include <bits/stdc++.h>
using namespace std;

int n, k, visited[500001][2];

int main() {
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    visited[n][0] = true;

    int time = 0;
    while (q.size()) {
        
        k += time;

        if (k > 500000) {
            cout << -1 << '\n';
            return 0;
        }

        if (visited[k][time % 2]) {
            cout << time << '\n';
            return 0;
        }

        time++;

        int qSize = q.size();
        // cout << "qSize: " << qSize << '\n';
        queue<int> temp;
        for (int i = 0; i < qSize; i++) {
            int cur = q.front(); q.pop();
            // cout << "cur: " << cur << '\n';
            for (int next : {cur + 1, cur - 1, cur * 2}) {
                // cout << "  next: " << next << '\n';
                if (0 <= next && next <= 500000 && !visited[next][time % 2]) {
                    temp.push(next);
                    visited[next][time % 2] = true;
                }
            }
        }
        
        q = temp;
    }
    // cout << -1 << '\n'; -> 없어도 됨
}