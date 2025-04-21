#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int line_cnt, a, b;
vector<pair<int, int>> v;

int main() {
    cin >> line_cnt;
    for (int i = 0; i < line_cnt; i++) {
        cin >> a >> b;
        v.push_back({ a, b });
    }

    sort(v.begin(), v.end());

    vector<int> lis;
    for (auto p : v) {
        int x = p.second;
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) lis.push_back(x);
        else *it = x;
    }

    int ans = line_cnt - lis.size();
    cout << ans;
}