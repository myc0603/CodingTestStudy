#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    int num = 0;
    while (n) {
        if (to_string(++num).find("666") != string::npos) {
            n--;
        }
    }
    cout << num << '\n';
}