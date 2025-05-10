// 2357과 같음
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
vector<int> arr, tree;

int init(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return tree[node];
    }

    int mid = (start + end) / 2;
    // int lmin = init(2 * node, start, mid);
    // int rmin = init(2 * node + 1, mid + 1, end);
    return tree[node] = min(init(2 * node, start, mid), init(2 * node + 1, mid + 1, end));
}

int query(int left, int right, int node, int start, int end) {
    if (right < start || end < left) return 1e9;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    int lmin = query(left, right, 2 * node, start, mid);
    int rmin = query(left, right, 2 * node + 1, mid + 1, end);
    return min(lmin, rmin);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    arr.resize(n + 1);
    for (int i = 1; i <= n; ++i) cin >> arr[i];

    int h = ceil(log2(n));
    tree.resize(1 << (h + 1));
    init(1, 1, n);

    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << query(a, b, 1, 1, n) << '\n';
    }
}