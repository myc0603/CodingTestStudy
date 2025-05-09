#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
// a: 0-based index, tree: 1-based index
vector<long long> a, tree;

long long init(int node, int start, int end) {
    if (start == end) { // leaf node
        return tree[node] = a[start];
    }
    long long lsum = init(node * 2, start, (start + end) / 2);
    long long rsum = init(node * 2 + 1, (start + end) / 2 + 1, end);
    return tree[node] = lsum + rsum;
}

long long sum(int left, int right, int node, int start, int end) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    
    long long lsum = sum(left, right, node * 2, start, (start + end) / 2);
    long long rsum = sum(left, right, node * 2 + 1, (start + end) / 2 + 1, end);
    return lsum + rsum;
}

void update(int index, int diff, int node, int start, int end) {
    if (index < start || end < index) return;
    tree[node] += diff;
    if (start != end) {
        update(index, diff, node * 2, start, (start + end)/ 2);
        update(index, diff, node + 2 + 1, (start + end) / 2 + 1, end);
    }

}

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    int h = ceil(log2(n));
    tree.resize(1 << (h + 1));
}