#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a[1003], reverse_a[1003], lis_info[1003], lds_info[1003], ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        reverse_a[i] = a[i];
    }

    reverse(reverse_a, reverse_a + n);
    vector<int> lis, lds;

    for (int i = 0; i < n; ++i) {
        auto lis_it = lower_bound(lis.begin(), lis.end(), a[i]);
        auto lds_it = lower_bound(lds.begin(), lds.end(), reverse_a[i]);

        lis_info[i] = lis_it - lis.begin() + 1;
        if (lis_it == lis.end()) lis.push_back(a[i]);
        else *lis_it = a[i];
        // lis_info[i] = lis_it - lis.begin() + 1;

        lds_info[i] = lds_it - lds.begin() + 1;
        if (lds_it == lds.end()) lds.push_back(reverse_a[i]);
        else *lds_it = reverse_a[i];
        // lds_info[i] = lds_it - lds.begin() + 1;
    }

    reverse(lds_info, lds_info + n);
    for (int i = 0; i < n; ++i) {
        ans = max(ans, lis_info[i] + lds_info[i]);
    }
    cout << ans - 1;
}