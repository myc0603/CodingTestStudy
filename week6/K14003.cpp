#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> lis, lis_idx, prev(n, -1);
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);
        int idx = it - lis.begin();
        
        if (it == lis.end()) {
            lis.push_back(a[i]);
            lis_idx.push_back(i);
        } else {
            *it = a[i];
            lis_idx[idx] = i;
        }

        if (idx > 0) {
            prev[i] = lis_idx[idx - 1];
        }
    }

    vector<int> real_lis;
    int cur_idx = lis_idx.back();
    while (cur_idx != -1) {
        real_lis.push_back(a[cur_idx]);
        cur_idx = prev[cur_idx];
    }
    reverse(real_lis.begin(), real_lis.end());

    string ans;
    for (int x : real_lis) ans += to_string(x) + ' ';
    cout << lis.size() << '\n' << ans;
}