#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[21], n, s;

int countSubsetSum(int cur, int sum) {
    if (cur == n) return sum == s ? 1 : 0;
    return countSubsetSum(cur + 1, sum) + countSubsetSum(cur + 1, sum + a[cur]);
}

void makeSubsetSum(int cur, int end, vector<int> &sums, int sum) {
    if (cur == end) {
        sums.push_back(sum);
        return;
    }

    makeSubsetSum(cur + 1, end, sums, sum);
    makeSubsetSum(cur + 1, end, sums, sum + a[cur]);
}

// n : 1 ~ 20, 2^20 ~ 100만
int main() {
    cin >> n >> s;
    for (int i = 0; i < n; ++i) cin >> a[i];

    // cout << countSubsetSum(0, 0) - (s == 0);
    
    vector<int> v1, v2;
    makeSubsetSum(0, n / 2, v1, 0);
    makeSubsetSum(n / 2, n, v2, 0);

    int cnt = 0;
    sort(v2.begin(), v2.end());
    for (int x : v1) {
        cnt += upper_bound(v2.begin(), v2.end(), s - x) - lower_bound(v2.begin(), v2.end(), s - x);
    }
    cout << cnt - (s == 0);
}