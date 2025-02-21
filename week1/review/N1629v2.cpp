#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    long long rem = 1; // = 1 % c
    long long temp = a % c;
    while (b) {
        if (b % 2) {
            rem = rem * temp % c;
        }
        temp = temp * temp % c;
        b /= 2;
    }
    cout << rem;
}