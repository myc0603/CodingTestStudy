#include <bits/stdc++.h>
using namespace std;
string s; int b, n;
int get(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    return c - 'A' + 10;
}
int main() {
    cin >> s >> b;
    reverse(s.begin(), s.end());
    int t = 1;
    for (char c : s) {
        int x = get(c);
        n += x * t;
        t *= b;
    }
    cout << n;
}