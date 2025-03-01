#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, j;
    cin >> n >> m >> j;

    int front = 1;
    int back = front + m - 1;

    int dis = 0;

    while (j--) {
        int pos; cin >> pos;

        if (pos < front) {
            dis += front - pos;
            front = pos;
            back = front + m - 1;
            continue;
        }
        if (pos > back) {
            dis += pos - back;
            back = pos;
            front = back - m + 1;
            continue;
        }
    }
    
    cout << dis << '\n';
}