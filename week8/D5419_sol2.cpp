#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ys, tree;
vector<pair<int, int>> points;

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        points.clear(); points.reserve(n);
        ys.clear();
        tree.clear(); tree.resize(n + 1);

        for (int i = 0; i < n; ++i) {
            int x, y; cin >> x >> y;
            points.emplace_back(x, -y);
            ys.push_back(-y);
        }

        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        for (auto &p : points) {
            p.second = lower_bound(ys.begin(), ys.end(), p.second) - ys.begin() + 1;
        }

        sort(points.begin(), points.end());

        long long cnt = 0;
        for (const auto &p : points) {
            cnt += query(tree, p.second);
            update(tree, p.second, 1);
        }

        cout << cnt << '\n';
    }
}