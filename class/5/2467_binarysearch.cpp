#include <iostream>
using namespace std;

int n, ph[100002], minPh = 2e9 + 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> ph[i];

    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        int toSearch = -ph[i];
        auto it = lower_bound(ph + i + 1, ph + n, toSearch);
        
        if (it != ph + n && *it == toSearch) {
            l = i;
            r = it - ph;
            break;
        }

        if (it != ph + n && abs(ph[i] + *it) < minPh) {
            minPh = abs(ph[i] + *it);
            l = i; r = it - ph;
        }
        if (i != it - 1 - ph && abs(ph[i] + *(it - 1)) < minPh) {
            minPh = abs(ph[i] + *(it - 1));
            l = i; r = it - ph - 1;
        }
    }
    cout << ph[l] << ' ' << ph[r] << '\n';
}