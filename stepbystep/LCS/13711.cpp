#include <iostream>
#include <vector>
using namespace std;
int n, a[100002], pos[100002];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        pos[x] = i;
    }
    vector<int> lis;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        auto it = lower_bound(lis.begin(), lis.end(), pos[x]);
        if (it == lis.end()) lis.push_back(pos[x]);
        else *it = pos[x];
    }
    cout << lis.size();
}