#include <iostream>
using namespace std;
int n, r, c, cnt;
int main() {
    cin >> n >> r >> c;
    for (int t = 1 << (n - 1); t; t >>= 1) {
        cnt += ((r >= t ? 2 : 0) + (c >= t ? 1 : 0)) * t * t;
        r %= t;
        c %= t;
    }
    cout << cnt;
}