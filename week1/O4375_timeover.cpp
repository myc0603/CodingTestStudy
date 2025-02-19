#include <bits/stdc++.h>
using namespace std;

int main() {
    // n이 한번 들어왔을 때 n : 1 ~ 10,000
    int n;
    cin >> n;

    // digits 자리수 하나씩 늘려가면서 확인
    int digits = 0;
    int remainder = 1; // = 1 % n
    long long ll = 1; // ll의 최대 범위를 모르겟네....
    while (remainder != 0) {
        digits++;
        ll *= 10;
        remainder += ll % n;
        remainder %= n;
    }
    // digits : 10의 몇승인지, 자릿수는 +1
    cout << (digits + 1);
}