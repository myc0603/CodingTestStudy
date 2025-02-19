#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (b <= c) {
        long long remainder = 1;
        for (int i = 0; i < b; i++) {
            remainder = remainder * a % c;
        }
        cout << remainder;
        return 0;
    }
    

    // b > c
    int rem[c];
    long long remainder = 1;
    for (int i = 1; i < c; i++) {
        remainder = remainder * a % c;
        rem[i] = remainder;
    }
    cout << rem[b % (c-1)];

    return 0;
}