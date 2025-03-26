#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    string pi = "pi";
    string ka = "ka";
    string chu = "chu";

    int len = s.length();
    int idx = 0;
    while (idx < len) {
        if (s.substr(idx, 2) == pi) {
            idx += 2;
            continue;
        }
        if (s.substr(idx, 2) == ka) {
            idx += 2;
            continue;
        }
        if (s.substr(idx, 3) == chu) {
            idx += 3;
            continue;
        }
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
}