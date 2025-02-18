#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    long long ll = 1;
    int remainder = 1; // long long? 0으로 초기화?
    for (int i = 0; i < b; i++) {
        ll *= a;
        remainder = remainder * a % c;
    }
    cout << remainder;
}