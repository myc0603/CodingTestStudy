#include <bits/stdc++.h>
using namespace std;

// 피보나치
// 잘 안되면 아예 다른 방법을 생각하거나 질문게시판 보자...

long long nCr(int n, int r) {
    vector<int> v;
    for (int x = n; x >= n - r + 1; x--) v.push_back(x);

    int cnt = 0;
    for (int y = 1; y <= r; y++) {
        for (int &x : v) {
            if (x % y == 0) {

                cnt++;

                x /= y;
                break;
            }
        }
    }

    if (cnt != r) cout << "something wrong\n";

    long long result = 1;
    for (int x : v) result = result * x % 10007;
    return result;


    // int temp = 1;
    // long long result = 1;
    // while (temp <= r) {
    //     result = result * n-- / temp++;
    //     // result = result % 10007;
    // }
    // return result;
}

int main() {
    int n; cin >> n;

    long long ans = 0;
    int r = 0;
    while (n >= r) {
        long long ncr = nCr(n, r);
        cout << "n: " << n << ", r: " << r << ", nCr: " << ncr << '\n';
        ans += nCr(n, r);
        ans %= 10007;
        n--; r++;
    }
    cout << ans;
}