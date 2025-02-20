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
    int a, b, c;
    cin >> a >> b >> c;

    cout << getRem(a, b, c) << '\n';
    return 0;
}