#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
vector<long long> a, tree;

long long init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    }
    long long lsum = init(2 * node, start, (start + end) / 2);
    long long rsum = init(2 * node + 1, (start + end) / 2 + 1, end);
    return tree[node] = lsum + rsum;
}

long long sum(int left, int right, int node, int start, int end) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    long long lsum = sum(left, right, 2 * node, start, (start + end) / 2);
    long long rsum = sum(left, right, 2 * node + 1, (start + end) / 2 + 1, end);
    return lsum + rsum;
}

void update(int index, long long diff, int node, int start, int end) {
    if (index < start || end < index) return;
    tree[node] += diff;
    if (start != end) {
        update(index, diff, 2 * node, start, (start + end) / 2);
        update(index, diff, 2 * node + 1, (start + end) / 2 + 1, end);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int h = ceil(log2(n));
    tree.resize(1 << (h + 1));
    init(1, 0, n - 1);

    for (int i = 0; i < m + k; ++i) {
        long long A, B, C;
        cin >> A >> B >> C;
        if (A == 1) { // update
            long long diff = C - a[B - 1];
            a[B-1] = C; // fix
            update(B - 1, diff, 1, 0, n - 1);
        } else {
            cout << sum(B - 1, C - 1, 1, 0, n - 1) << '\n';
        }
    }
}