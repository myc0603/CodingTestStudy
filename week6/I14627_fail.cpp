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
    cout << "check -> mid: " << mid << ", cnt: " << cnt << '\n';
    return cnt >= c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // cin >> s >> c;

    long long left = 0, right = 1e9 + 1; // left 0 -> 1
    // for (int i = 0; i < s; i++) {
    //     long long x; cin >> x;
    //     lengths.push_back(x);
    //     // right = max(right, x);
    // }
    
//     999999 1000000
// 1000000000 x 999999
// 499 9990 0000 0000 -> 답
// left ->5억
    // s: 99만9999, c: 백만
    s = 9; c = 10;
    for (int i = 0; i < s; i++) {
        lengths.push_back(10000); // 10억 -> 2 * 999999 = 1,999,998
    }

    while (left + 1 < right) {
        cout << "l, r: " << left << ' ' << right << '\n';
        long long mid = (left + right) / 2LL;
        if (check(mid)) left = mid;
        else right = mid;
    }

    cout << "find left: " << left << "\n";

    // long long ans = 0;
    // if (left) {
    //     for (long long len : lengths) {
    //         ans += len % left;
    //     }
    // } else {
    //     for (long long len : lengths) {
    //         ans += len;
    //     }
    // }

    long long sum = 0;
    for (long long len : lengths) {
        sum += len;
    }
    long long ans = sum - left * c;

    cout << ans;
}