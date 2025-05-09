#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n = 10, a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 0-based
vector<long long> tree, lazy; // 1-based

long long init(int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
        return tree[node];
    }

    int mid = (start + end) / 2;
    tree[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
    return tree[node];
}

// update(), sum()을 하면서 방문하게 되면 lazyUpdate!!
void lazyUpdate(int node, int start, int end) {
    if (lazy[node] == 0) return;

    tree[node] += lazy[node] * (end - start + 1);
    if (start != end) {
        lazy[2*node] += lazy[node];
        lazy[2*node+1] += lazy[node];
    }
    lazy[node] = 0;
}

long long sum(int left, int right, int node, int start, int end) {
    lazyUpdate(node, start, end);
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return sum(left, right, 2 * node, start, mid) + sum(left, right, 2 * node + 1, mid + 1, end);
}

void update(int left, int right, long long diff, int node, int start, int end) {
    lazyUpdate(node, start, end);
    if (right < start || end < left) return;
    if (left <= start && end <= right) {
        // 여기까지만 업데이트하고 멈춤 자식 노드는 lazy에 등록만 한다.
        tree[node] += diff * (end - start + 1);
        if (start != end) {
            lazy[2*node] += diff;
            lazy[2*node+1] += diff;
        }
        return;
    }

    int mid = (start + end) / 2;
    update(left, right, diff, 2 * node, start, mid);
    update(left, right, diff, 2 * node + 1, mid + 1, end);
    tree[node] = tree[2*node] + tree[2*node + 1];
}

int main() {
    // cin >> n;
    // for (int i = 0; i < n; ++i) cin >> a[i];
    int h = ceil(log2(n));
    tree.resize(1 << (h + 1));
    lazy.resize(tree.size());
    init(1, 0, n - 1);

    cout << "init segment tree: ";
    for (auto x : tree) cout << x << ' ';
    cout << '\n';

    update(3, 4, 2, 1, 0, 9);
    cout << "\ntree: ";
    for (auto x : tree) cout << x << ' ';
    cout << "\nlazy: ";
    for (auto x : lazy) cout << x << ' ';
    cout << '\n';

    update(3, 9, 1, 1, 0, 9);
    cout << "\ntree: ";
    for (auto x : tree) cout << x << ' ';
    cout << "\nlazy: ";
    for (auto x : lazy) cout << x << ' ';
    cout << '\n';
    
    cout << "\nsum 4 to 8: " << sum(4, 8, 1, 0, 9);
    cout << "\ntree: ";
    for (auto x : tree) cout << x << ' ';
    cout << "\nlazy: ";
    for (auto x : lazy) cout << x << ' ';
    cout << '\n';
}