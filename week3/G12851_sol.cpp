#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int minSec;
    // int cnt = 0;
    bool flag = false;
    // map<int, int> dis; // val, distance
    int dis[200004] = {}; // val, distance
    // map<int, int> cnt;
    int cnt[200004] = {}; // val, count

    // bfs
    queue<int> q;
    q.push(n);
    // dis[n] = 0;
    dis[n] = 1;
    cnt[n] = 1;

    while (q.size()) {

        int cur = q.front(); q.pop();
        
        int nums[] = {cur - 1, cur + 1, cur * 2};
        for (int num : nums) {
            if (num < 0 || num > 200000) continue;
            // if (flag && dis[cur] > minSec) continue;
            // if (dis.find(num) == dis.end()) {
            if (!dis[num]) {
                q.push(num);
                dis[num] = dis[cur] + 1;
            }
            if (dis[num] == dis[cur] + 1) {
                flag = true;
                minSec = dis[cur];
                cnt[num] += cnt[cur];
            }
        }
    }

    cout << dis[k] - 1 << '\n' << cnt[k] << '\n';
}