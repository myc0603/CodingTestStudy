#include <bits/stdc++.h>
using namespace std;

int a[64][64];

string compress(int y, int x, int size) {

    if (size == 1) return to_string(a[y][x]);

    int nextSize = size / 2;
    string s1 = compress(y, x, nextSize);
    string s2 = compress(y, x + nextSize, nextSize);
    string s3 = compress(y + nextSize, x, nextSize);
    string s4 = compress(y + nextSize, x + nextSize, nextSize);
    if (s1 == s2 && s2 == s3 && s3 == s4 && s1.size() == 1) {
        return s1;
    }
    return "(" + s1 + s2 + s3 + s4 + ")";
}

int main() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            a[i][j] = s[j] - '0';
        }
    }

    cout << compress(0, 0, n) << '\n';
}