#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, l, pos[53], lens[53], cnt[53];

int main() {
    cin >> n >> m >> l;
    pos[0] = 0;
    for (int i = 1; i <= n; ++i) cin >> pos[i];
    pos[n+1] = l;
    sort(pos, pos + n + 2);

    lens[0] = pos[0];
    priority_queue<pair<int, int>> pq;
    pq.push( {lens[0], 0} );
    for (int i = 1; i <= n + 1; ++i) {
        lens[i] = pos[i] - pos[i-1];
        pq.push( {lens[i], i} );
    }

    while (m--) {
        int len = pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        ++cnt[idx];
        len = (lens[idx] + cnt[idx]) / (cnt[idx] + 1);
        pq.push( {len, idx} );
    }
    cout << pq.top().first;
}