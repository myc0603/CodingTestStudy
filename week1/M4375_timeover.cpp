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
    // n이 한번 들어왔을 때 n : 1 ~ 10,000
    int n;
    cin >> n;

    // digits 자리수 하나씩 늘려가면서 확인
    int digits = 0;
    while (!check(n, digits)) {
        digits++;
    }
    // digits : 10의 몇승인지
    cout << (digits + 1);
}