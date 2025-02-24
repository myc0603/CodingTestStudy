#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, j;
    cin >> n >> m >> j;
    int front = 1;
    int back = front + m - 1;
    int tot = 0;
    while (j--) {
        int pos; cin >> pos;
        if (pos > back) {
            int cnt = pos - back;
            tot += cnt;
            front += cnt;
            back += cnt;
        } else if (pos < front) {
            int cnt = front - pos;
            tot += cnt;
            front -= cnt;
            back -= cnt;
        }
    }
    cout << tot << '\n';
}