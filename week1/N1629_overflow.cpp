#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    long long remainder = 1; // remainder * a -> 이 부분에서 int 범위를 벗어날 수 있기 때문에 long long으로 선언
    long long temp = 1; // 어떻게든 temp에 오버플로 발생
    for (int i = 0; b != 0; i++) {
        temp = i ? temp * temp : a; // i가 0인 처음에만 a 대입, 그 다음부턴 제곱
        cout << temp << '\n';
        if (b % 2 == 1) {
            remainder = (remainder * temp) % c;
        }
        b /= 2;
    }
    cout << remainder << '\n';
    return 0;
}