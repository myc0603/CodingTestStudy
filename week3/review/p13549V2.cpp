#include <bits/stdc++.h>
using namespace std;

int n, k, visited[200003];

int main() {
    cin >> n >> k;

    if (n == k || n * 2  == k) {
        cout << 0;
        return 0;
    }

    queue<int> q;
    visited[n] = 1;
    q.push(n);

    while (q.size()) {
        int cur = q.front(); q.pop();

        // cout << cur << ": " << visited[cur] - 1 << '\n';
        if (cur == k) {
            cout << visited[cur] - 1;
            return 0;
        }
        if (cur * 2 <= 100000 && (!visited[cur*2] || visited[cur] < visited[cur*2])) {
            visited[cur*2] = visited[cur];
            q.push(cur*2);
        }
        for (int num : {cur + 1, cur - 1}) {
            if (0 <= num && num <= 100000 && (!visited[num] || visited[cur] + 1 < visited[num])) {
                visited[num] = visited[cur] + 1;
                q.push(num);
            }
        }
    }
}