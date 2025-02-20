#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    long long rem = 1;
    long long temp = 1;
    for (int i = 0; b > 0; i++) {
        temp = i == 0 ? a % c : temp * temp % c;
        if (b % 2) {
            rem = rem * temp % c;
        }
        b /= 2;
    }
    cout << rem << '\n';
    return 0;
}