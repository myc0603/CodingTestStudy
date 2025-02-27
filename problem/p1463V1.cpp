#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int dis[n+1] = {};
    queue<int> q;
    q.push(1);
    while (q.size()) {
        int cur = q.front(); q.pop();

        if (cur == n) {
            cout << dis[cur] << '\n';
            return 0;
        }

        int nums[] = {cur+1, cur*2, cur*3};
        for (int num : nums) {
            if (num <= n && dis[num] == 0) {
                q.push(num);
                dis[num] = dis[cur] + 1;
            }
        }
    }
}