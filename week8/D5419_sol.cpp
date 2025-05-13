#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
    if (p1.first == p2.first) return p2.second < p1.second;
    return p1.first < p2.first;
}

int query(vector<int> &tree, int idx) {
    int result = 0;
    while (idx > 0) {
        result += tree[idx];
        idx -= idx & -idx;
    }
    return result;
}

void update(vector<int> &tree, int idx, int val) {
    while (idx < tree.size()) {
        tree[idx] += val;
        idx += idx & -idx;
    }
}

int indexOf(const vector<int> &v, int val) {
    int l = -1, r = v.size();
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (v[mid] <= val) r = mid;
        else l = mid;
    }
    return r + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, int>> pnts(n);
        vector<int> ys(n), tree(n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> pnts[i].first >> pnts[i].second;
            ys[i] = pnts[i].second;
        }

        sort(pnts.begin(), pnts.end(), cmp);
        sort(ys.begin(), ys.end(), greater<>());

        // ys.erase(unique(ys.begin(), ys.end()), ys.end());

        long long cnt = 0;
        update(tree, indexOf(ys, pnts[0].second), 1);
        for (int i = 1; i < n; ++i) {
            int idx = indexOf(ys, pnts[i].second);
            cnt += query(tree, idx);
            update(tree, idx, 1);
        }

        cout << cnt << '\n';
    }
}