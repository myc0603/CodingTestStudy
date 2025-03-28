#include <bits/stdc++.h>
#define prev asdf

using namespace std;

int n, k, visited[200003], prev[200003];

int main() {
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    visited[n] = 1;

    while (q.size()) {
        int cur = q.front(); q.pop();

        for (int next : {cur + 1, cur - 1, cur * 2}) {
            if (0 <= next && next <= 200000 && !visited[next]) {
                q.push(next);
                visited[next] = visited[cur] + 1;
                prev[next] = cur;
            }
        }
        if (visited[k] != 0) break;
    }

    cout << visited[k] - 1 << '\n';
    
    vector<int> path;
    for (int cur = k; cur != n; cur = prev[cur]) {
        path.push_back(cur);
    }
    path.push_back(n);

    string ans;
    for (int i = path.size() - 1; i >= 0; i--) {
        ans += to_string(path[i]) + ' ';
    }
    cout << ans;
}