#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
long long arr[1000002];
vector<long long> tree;

void update(int i, long long val) {
    while (i <= n) {
        tree[i] += val;
        i += i & -i;
    }
}

long long sum(int i) {
    long long result = 0;
    while (i > 0) {
        result += tree[i];
        i -= i & -i;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> k;
    tree.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        update(i, arr[i]);
    }

    m += k;
    while (m--) {
        int a; cin >> a;
        if (a == 1) {
            int b; long long c;
            cin >> b >> c;
            long long diff = c - arr[b];
            arr[b] = c;
            update(b, diff);
        } else {
            int b, c;
            cin >> b >> c;
            cout << sum(c) - sum(b - 1) << '\n';
        }
    }
}