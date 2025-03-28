#include <bits/stdc++.h>
using namespace std;

int n, k, visited[200003], cnt[200003];

int main() {
    cin >> n >> k;
    
    if (n == k) {
        cout << 0 << '\n' << 1 << '\n';
        return 0;
    }

    queue<int> q;
    q.push(n);
    visited[n] = 1;
    cnt[n] = 1;

    while (q.size()) {
        int cur = q.front(); q.pop();

        for (int next : {cur + 1, cur - 1, cur * 2}) {
            // if (0 <= next && next <= 200000) {
            if (0 <= next && next <= 100000) {
                if (!visited[next]) {
                    visited[next] = visited[cur] + 1;
                    cnt[next] = cnt[cur];
                    q.push(next);
                } else if (visited[next] == visited[cur] + 1) {
                    cnt[next] += cnt[cur];
                }
                // k를 찾을 수 있는 방법을 다 찾아야하기 때문에 처음으로 k를 찾자마자 출력하고 리턴하면 안 됨
                // if (next == k) {
                //     cout << visited[cur] << '\n' << cnt[next] << '\n';
                //     return 0;
                // }
            }
        }
    }

    cout << visited[k] - 1 << '\n' << cnt[k] << '\n';
}