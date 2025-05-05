#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s, a[41];

void makeSubsetSum(int cur, int end, vector<int> &sums, int sum) {
    if (cur == end) {
        sums.push_back(sum);
        return;
    }

    makeSubsetSum(cur + 1, end, sums, sum);
    makeSubsetSum(cur + 1, end, sums, sum + a[cur]);
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> v1, v2;
    makeSubsetSum(0, n / 2, v1, 0);
    makeSubsetSum(n / 2, n, v2, 0);
    sort(v2.begin(), v2.end());

    long long cnt = 0;
    for (int x : v1) {
        cnt += upper_bound(v2.begin(), v2.end(), s - x) - lower_bound(v2.begin(), v2.end(), s - x);
    }
    cout << cnt - (s == 0);
}