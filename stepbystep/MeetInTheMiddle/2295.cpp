#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int n, a[1002];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    // a + b + c = d를 만족하는 d의 최댓값 찾기
    // 1. a, b 찾기 a, b는 같을 수도 있음
    vector<int> twoSums;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            twoSums.push_back(a[i] + a[j]);
        }
    }
    sort(twoSums.begin(), twoSums.end());

    // c, d 찾기
    int ans = 0;
    for (int i = 0; i < n; ++i) { // d
        for (int j = 0; j < n; ++j) { // c
            int target = a[i] - a[j];
            auto it = lower_bound(twoSums.begin(), twoSums.end(), target);
            if (it != twoSums.end() && *it == target) ans = max(ans, a[i]);
        }
    }

    cout << ans;
}