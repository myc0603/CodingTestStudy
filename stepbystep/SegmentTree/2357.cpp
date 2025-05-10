#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m, a[100002];
vector<int> minTree, maxTree;

void init(int node, int start, int end) {
    if (start == end) {
        minTree[node] = a[start];
        maxTree[node] = a[start];
        return;
    }

    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    minTree[node] = min(minTree[2*node], minTree[2*node + 1]);
    maxTree[node] = max(maxTree[2*node], maxTree[2*node + 1]);
}

int minQuery(int left, int right, int node, int start, int end) {
    if (right < start || end < left) return 2e9;
    if (left <= start && end <= right) return minTree[node];

    int mid = (start + end) / 2;
    int leftResult = minQuery(left, right, 2 * node, start, mid);
    int rightResult = minQuery(left, right, 2 * node + 1, mid + 1, end);
    return min(leftResult, rightResult);
}

int maxQuery(int left, int right, int node, int start, int end) {
    if (right < start || end < left) return -1;
    if (left <= start && end <= right) return maxTree[node];

    int mid = (start + end) / 2;
    int leftResult = maxQuery(left, right, 2 * node, start, mid);
    int rightResult = maxQuery(left, right, 2 * node + 1, mid + 1, end);
    return max(leftResult, rightResult);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int h = ceil(log2(n));
    minTree.resize(1 << (h + 1));
    maxTree.resize(1 << (h + 1));

    for (int i = 1; i <= n; ++i) cin >> a[i];
    init(1, 1, n);

    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << minQuery(l, r, 1, 1, n) << ' ' << maxQuery(l, r, 1, 1, n) << '\n';
    }
}