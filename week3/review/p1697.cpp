#include <bits/stdc++.h>
using namespace std;

int n, k, visited[200004];

int main() {
    cin >> n >> k;
    
    if (n == k) {
        cout << 0 << '\n';
    }
    
    queue<int> q;
    q.push(n);
    visited[n] = 1;

    while (q.size()) {
        int cur = q.front(); q.pop();

        for (int next : {cur + 1, cur - 1, cur * 2}) {
            if (0 <= next && next <= 200000 && !visited[next]) {
                q.push(next);
                visited[next] = visited[cur] + 1;
                if (next == k) {
                    cout << visited[cur] << '\n';
                    return 0;
                }
            }
        }
    }
}