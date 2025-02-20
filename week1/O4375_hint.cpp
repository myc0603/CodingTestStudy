#include <bits/stdc++.h>
using namespace std;

long long getRem(int a, int b, int c) {
    if (b == 1) return a % c;

    long long rem = getRem(a, b/2, c);
    rem = rem * rem % c;
    if (b % 2) rem = rem * a % c;
    return rem;
}

int main() {
    // n이 한번 들어왔을 때 n : 1 ~ 10,000
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    int digits = 0;
    int rem = 1;
    while(rem) {
        digits++;
        rem = (rem + getRem(10, digits, n)) % n;
        cout << "digits: " << digits << " rem: " << rem << '\n';
    }

    cout << digits + 1 << '\n';
    return 0;
}