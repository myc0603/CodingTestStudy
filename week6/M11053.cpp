#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;

    vector<int> lis;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) lis.push_back(x);
        else *it = x;
    }

    cout << lis.size();
}