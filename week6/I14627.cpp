#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, chickens;
vector<long long> lengths;

bool check(long long mid) {
    long long order = 0;
    for (int len : lengths) {
        order += len / mid;
    }
    return order >= chickens;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> chickens;

    long long left = 0, right = 1e9;
    for (int i = 0; i < n; i++) {
        long long x; cin >> x;
        lengths.push_back(x);
        right = min(right, x);
    }
    
    while (left + 1 < right) {
        long long mid = (left + right) / 2;
        if (check(mid)) left = mid;
        else right = mid;
    }

    long long ans = 0;
    for (long long len : lengths) {
        ans += len % left;
    }
    cout << ans;
}