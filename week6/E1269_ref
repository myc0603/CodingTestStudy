#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0, diff = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            i++; j++;
        } else if (a[i] < b[j]) {
            diff++; i++;
        } else {
            diff++; j++;
        }
    }
    diff += (n - i) + (m - j);

    cout << diff;
    return 0;
}
