#include <bits/stdc++.h>
using namespace std;

int main() {
    int start, k;
    cin >> start >> k;

    if (start == k) {
        cout << 0 << '\n' << 1 << '\n';
    }

    int minSec;
    int cnt = 0;
    bool flag = false;
    map<int, int> dis;

    // bfs
    queue<int> q;
    q.push(start);
    dis[start] = 0;

    while (q.size()) {

        int cur = q.front(); q.pop();
        
        int nums[] = {cur - 1, cur + 1, cur * 2};
        for (int num : nums) {
            if (num < 0 || num >= 100000) continue; // ?
            if (flag && dis[cur] >= minSec) continue;
            if (dis.find(num) == dis.end()) {
                q.push(num);
                dis[num] = dis[cur] + 1;
            }
            if (num == k) {
                flag = true;
                minSec = dis[cur] + 1;
                cnt++;
            }
        }
    }

    cout << minSec << '\n' << cnt << '\n';
}