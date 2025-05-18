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

        if (lis_it == lis.end()) {
            lis.push_back(a[i]);
            lis_info[i] = max(lis_info[i], (int) lis.size());
        } else *lis_it = a[i];

        if (lds_it == lds.end()) {
            lds.push_back(reverse_a[i]);
            lds_info[n-1-i] = max(lds_info[n-1-i], (int) lds.size());
        }
        else *lds_it = reverse_a[i];
    }

    for (int i = 0; i < n; ++i) {
        ans = max(ans, lis_info[i] + lds_info[i]);
    }
    cout << ans - 1;
}

/**
 * input
 * 44
 * 76 108 982 294 720 81 8 519 630 646 83 942 383 942 188 6 154 56 830 242 626 783 710 630 909 842 608 116 638 701 914 605 381 429 947 46 261 977 183 708 51 312 333 277
 * outupt 15
 * answer 17
 */