#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int n, idx[100002];
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
    }
    sort(lines.begin(), lines.end());

    vector<int> lis;
    for (int i = 0; i < n; ++i) {
        int a_idx = lines[i].first;
        int value = lines[i].second;

        auto it = lower_bound(lis.begin(), lis.end(), value);
        int pos = it - lis.begin();
        if (it == lis.end()) lis.push_back(value);
        else *it = value;

        idx[i] = pos;
    }

    int len = lis.size();
    cout << n - len << '\n';
    
    vector<int> v;
    --len;
    for (int i = n - 1; i >= 0; --i) {
        if (idx[i] == len) { // in lis
            --len;
        } else { // not in lis
            v.push_back(lines[i].first);
        }
    }
    reverse(v.begin(), v.end());
    for (int a : v) cout << a << '\n';
}