#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int s, c;
vector<long long> lengths;

bool check(long long mid) {
    long long cnt = 0;
    for (long long len : lengths) {
        cnt += len / mid;
    }
    return cnt >= c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s >> c;

    long long sum = 0;
    for (int i = 0; i < s; i++) {
        long long x; cin >> x;
        lengths.push_back(x);
        sum += x;
    }

    long long left = 0, right = 1e9 + 1;
    while (left + 1 < right) {
        long long mid = (left + right) / 2LL;
        if (check(mid)) left = mid;
        else right = mid;
    }

    cout << sum - left * c;
}