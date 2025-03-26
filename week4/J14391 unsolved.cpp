#include <bits/stdc++.h>
using namespace std;

int n, m, a[4][4], b[4][4];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            a[4-n+i][4-m+j] = s[j] - '0';
            b[4-m+j][4-n+i] = s[j] - '0';
        }
    }

    int sum1 = 0;
    for (int i = 0; i < 4; i++) {
        int temp = a[i][0] * 1000 + a[i][1] * 100 + a[i][2] * 10 + a[i][3];
        sum1 += temp;
        // cout << "temp1: " << temp << '\n';
    }

    int sum2 = 0;
    for (int i = 0; i < 4; i++) {
        int temp = b[i][0] * 1000 + b[i][1] * 100 + b[i][2] * 10 + b[i][3];
        sum2 += temp;
        // cout << "temp2: " << temp << '\v';
    }

    cout << max(sum1, sum2) << '\n';
}