#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<double> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    double ans = 0;
    double cur = 1;
    for (double x : v) {
        cur *= x;
        ans = max(ans, cur);
        if (cur < 1) cur = 1;
    }

    // double ans = 0;
    // double cur = v[0];
    // for (int i = 1; i < n; i++) {
    //     cur = max(cur * v[i], v[i]);
    //     ans = max(ans, cur);
    // }

    cout << fixed << setprecision(3) << ans;
}