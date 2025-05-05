#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c, w[31];

void makeSubsetSum(int cur, int end, vector<long long> &sums, long long sum) {
    if (sum > c) return;
    if (cur == end) {
        sums.push_back(sum);
        return;
    }

    makeSubsetSum(cur + 1, end, sums, sum + w[cur]);
    makeSubsetSum(cur + 1, end, sums, sum);
}

int main() {
    cin >> n >> c;
    for (int i = 0; i < n; ++i) cin >> w[i];

    vector<long long> v1, v2;
    makeSubsetSum(0, n / 2, v1, 0);
    makeSubsetSum(n / 2, n, v2, 0);

    long long cnt = 0;
    sort(v2.begin(), v2.end());
    for (int x : v1) {
        cnt += upper_bound(v2.begin(), v2.end(), c - x) - v2.begin();
    }
    cout << cnt;
}