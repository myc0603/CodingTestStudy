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
        
        if (it != ph + n) {
            int sum = abs(ph[i] + *it);
            if (sum < minPh) {
                minPh = sum;
                l = i; r = it - ph;
            }
            if (sum == 0) break;
        }

        if (it != ph + i + 1) {
            int sum = abs(ph[i] + *(it - 1));
            if (sum < minPh) {
                minPh = sum;
                l = i; r = it - ph - 1;
            }
        }
    }
    cout << ph[l] << ' ' << ph[r] << '\n';
}