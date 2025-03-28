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
    do {
        visited[n] = 1;
        q.push(n);
        n <<= 1;
    } while (n != 0 && n <= 100000);

    while (q.size()) {
        int cur = q.front(); q.pop();

        if (cur == k) {
            cout << visited[cur] - 1;
            return 0;
        }
        for (int num : {cur + 1, cur - 1}) {
            if (0 <= num && num <= 100000 && !visited[num]) {
                do {
                    visited[num] = visited[cur] + 1;
                    q.push(num);
                    num <<= 1;
                } while (num != 0 && num <= 100000 && !visited[num]);
            }
        }
    }
}