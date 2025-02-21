#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int digits = 1;
        for (int rem = 1; rem; digits++) {
            if (n == 1) break;
            rem = (rem * 10 + 1) % n;
        }
        cout << digits << '\n';
    }
}