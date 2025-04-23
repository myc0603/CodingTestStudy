#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    vector<int> sorted = v;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    string ans;
    for (int num : v) {
        auto it = lower_bound(sorted.begin(), sorted.end(), num);
        ans += to_string(it - sorted.begin()) + ' ';        
    }
    cout << ans;
}