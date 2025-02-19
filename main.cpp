#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (!(n & 1)) {
        cout << "it's even\n";
    } else {
        cout << "it's odd\n";
    }

    if (!n & 1) {
        cout << "it's even\n";
    } else {
        cout << "!n: " << !n << '\n';
        cout << "it's odd\n";
    }

    if (~n & 1) {
        cout << "it's even\n";
    } else {
        cout << "it's odd\n";
    }
}