#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Sum {
    int i, j, sum;
    Sum() {}
    Sum(int _i, int _j, int _sum) : i(_i), j(_j), sum(_sum) {}
    bool operator<(const Sum &s) {
        return sum < s.sum;
    }
};

int n, a[602], ans = 2e9;
vector<Sum> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    v.reserve(n * (n - 1) / 2);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            v.emplace_back(i, j, a[i] + a[j]);
        }
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            if (v[i].i == v[j].i || v[i].i == v[j].j
                || v[i].j == v[j].i || v[i].j == v[j].j) continue;
                
            ans = min(ans, v[j].sum - v[i].sum);
            break;
        }
    }

    cout << ans;
}