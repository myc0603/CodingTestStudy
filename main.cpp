#include <bits/stdc++.h>
using namespace std;

bool check(int n, int digits) {
    int remainder = 1 % n;
    long long ll = 1;
    for (int i = 1; i <= digits; i++) {
        ll *= 10;
        remainder += ll % n;
        remainder %= n;
    }
    return remainder == 0;
}

int main() {
    int n;
    cin >> n;

    int digits = 0;
    while (!check(n, digits)) {
        digits++;
    }
    cout << (digits + 1);    
}