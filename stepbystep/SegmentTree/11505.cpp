#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MOD = 1'000'000'007;
int n, m, k;
// 큰 수 두 개의 곱셈 결과는 int 범위를 벗어나 오버플로우 발생 가능성 있음
vector<long long> tree, arr;

long long init(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return tree[node];
    }

    int mid = (start + end) / 2;
    tree[node] = init(2 * node , start, mid) * init(2 * node + 1, mid + 1, end) % MOD;
    return tree[node];
}

void update(int index, long long value, int node, int start, int end) {
    if (index < start || end < index) return;
    // divide, product can be zero
    // tree[node] = tree[node] / divide * product % MOD;
    if (start != end) {
        int mid = (start + end) / 2;
        update(index, value, node * 2, start, mid);
        update(index, value, node * 2 + 1, mid + 1, end);
        tree[node] = tree[node*2] * tree[node*2+1] % MOD;
    } else {
        tree[node] = value;
    }
}

long long query(int left, int right, int node, int start, int end) {
    if (right < start || end < left) return 1;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    auto l = query(left, right, node * 2, start, mid);
    auto r = query(left, right, node * 2 + 1, mid + 1, end);
    return (l * r) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    arr.resize(n + 1);
    for (int i = 1; i <= n; ++i) cin >> arr[i];

    int h = ceil(log2(n));
    tree.resize(1 << (h + 1));
    init(1, 1, n);

    m += k;
    while (m--) {
        int a, b; long long c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(b, c, 1, 1, n);
            // arr[b] = c; // 이거 안 해도 됨
        } else {
            cout << query(b, c, 1, 1, n) << '\n';
        }
    }
}