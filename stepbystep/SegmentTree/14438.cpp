#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
vector<int> tree, a;

int init(int node, int s, int e) {
    if (s == e) {
        tree[node] = a[s];
        return tree[node];
    }

    int mid = (s + e) / 2;
    tree[node] = min(init(node * 2, s, mid), init(node * 2 + 1, mid + 1, e));
    return tree[node];
}

void update(int i, int node, int s, int e) {
    if (i < s || e < i) return;
    if (s == e) { // i == s == e
        tree[node] = a[s]; // update() 실행하기전에 a[s] 업데이트
        return;
    }
    
    int mid = (s + e) / 2;
    update(i, 2 * node, s, mid);
    update(i, 2 * node + 1, mid + 1, e);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}

int query(int l, int r, int node, int s, int e) {
    if (r < s || e < l) return 1e9;
    if (l <= s && e <= r) return tree[node];

    int mid = (s + e) / 2;
    return min(query(l, r, 2 * node, s, mid), query(l, r, 2 * node + 1, mid + 1, e));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int h = ceil(log2(n));
    tree.resize(1 << (h + 1));
    init(1, 1, n);

    cin >> m;
    while (m--) {
        int q, i, j;
        cin >> q >> i >> j;
        if (q == 1) {
            a[i] = j;
            update(i, 1, 1, n);
        } else {
            cout << query(i, j, 1, 1, n) << '\n';
        }
    }
}