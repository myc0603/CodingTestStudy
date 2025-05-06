#include <iostream>
#include <algorithm>
using namespace std;

int n, a[602], ans = 2e9;

void go(int i, int j) {
    int l = i + 1, r = j - 1;
    int sum = a[i] + a[j];
    while (l < r) {
        int temp = a[l] + a[r];
        ans = min(ans, abs(temp - sum));
        if (temp > sum) --r;
        else if (temp < sum) ++l;
        else break;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 3; j < n; ++j) {
            go(i, j);
        }
    }

    cout << ans;
}