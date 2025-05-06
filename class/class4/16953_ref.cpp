#include <iostream>
using namespace std;

int a, b, cnt;

int main() {
    cin >> a >> b;

    // b는 짝수거나 1의 자리가 1이어야 함
    while (a < b) {
        if (b % 2 == 0) b /= 2;
        else if (b % 10 == 1) b = (b - 1) / 10;
        else break;
        ++cnt;

        if (a == b) {
            cout << cnt + 1;
            return 0;
        }
    }
    cout << -1;
}