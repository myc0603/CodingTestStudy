#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int n, pre[500002];
vector<int> as;
vector<pair<int, int>> lines;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    lines.reserve(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        lines.emplace_back(a, b);
        as.push_back(a);
    }
    sort(lines.begin(), lines.end());
    sort(as.begin(), as.end());

    vector<int> lis, lis_idx;
    for (auto p : lines) {
        int a = p.first;
        int value = p.second;
        auto it = lower_bound(lis.begin(), lis.end(), value);
        int cur_idx = it - lis.begin();
        if (it == lis.end()) {
            lis.push_back(value);
            lis_idx.push_back(a);
        } else {
            *it = value;
            lis_idx[cur_idx] = a;
        }
        
        if (cur_idx != 0) pre[a] = lis_idx[cur_idx-1];
    }

    vector<int> real_lis;
    int cur_idx = lis_idx.back();
    while (cur_idx) {
        real_lis.push_back(cur_idx);
        cur_idx = pre[cur_idx];
    }
    reverse(real_lis.begin(), real_lis.end());

    cout << n - lis.size() << '\n';

    // unordered_set<int> set;
    // for (int a : real_lis) set.insert(a);
    // for (int a : as) {
    //     if (!set.count(a)) cout << a << '\n';
    // }


    int idx = 0;
    for (int a : as) {
        if (a != real_lis[idx]) cout << a << '\n';
        else if (idx < real_lis.size() - 1) ++idx;
    }
}