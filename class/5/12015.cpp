#include <iostream>
#include <vector>
using namespace std;

int n, a[1000003];
vector<int> lis;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);
        if (it == lis.end()) lis.push_back(a[i]);
        else *it = a[i];
    }
    cout << lis.size();
}