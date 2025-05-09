#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m, a[100003];
vector<int> tree; // 최솟값의 index 저장

int init(int node, int start, int end) {
    if (start == end) {
        tree[node] = start;
        return tree[node];
    }
    int mid = (start + end) / 2;
    int lMinIdx = init(2*node, start, mid);
    int rMinIdx = init(2*node + 1, mid + 1, end);
    tree[node] = a[lMinIdx] <= a[rMinIdx] ? lMinIdx : rMinIdx;
    return tree[node];
}

void update(int index, int value, int node, int start, int end) {
    if (index < start || end < index) return;
    
    // leaf node는 업데이트 필요 없음
    if (start != end) {
        int mid = (start + end) / 2;
        update(index, value, 2 * node, start, mid);
        update(index, value, 2 * node + 1, mid + 1, end);

        int lMinIdx = tree[2 * node];
        int rMinIdx = tree[2 * node + 1];
        tree[node] = a[lMinIdx] <= a[rMinIdx] ? lMinIdx : rMinIdx;
    }
}

int query(int left, int right, int node, int start, int end) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    int lMinIdx = query(left, right, 2*node, start, mid);
    int rMinIdx = query(left, right, 2*node+1, mid + 1, end);
    return a[lMinIdx] <= a[rMinIdx] ? lMinIdx : rMinIdx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    a[0] = 2e9;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int h = ceil(log2(n));
    tree.resize(1 << (1 + h));
    init(1, 1, n);

    // cout << "tree:"; for (auto x : tree) cout << x << ' '; cout << '\n';

    cin >> m;
    while (m--) {
        int q, i, j;
        cin >> q >> i >> j;
        if (q == 1) { // update
            a[i] = j;
            update(i, j, 1, 1, n);
            // cout << "after update\n";
            // cout << "tree:"; for (auto x : tree) cout << x << ' '; cout << '\n';
        } else { // query
            cout << query(i, j, 1, 1, n) << '\n';
        }
    }
}