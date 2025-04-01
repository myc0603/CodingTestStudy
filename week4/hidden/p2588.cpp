#include <iostream>
using namespace std;

// 곱셈
int main() {
    int a; string b;
    cin >> a >> b;
    int temp[3];
    for (int i = 2; i >= 0; i--) {
        temp[i] = a * (b[i] - '0');
    }
    int sum = temp[0] * 100 + temp[1] * 10 + temp[2];
    cout << temp[2] << '\n';
    cout << temp[1] << '\n';
    cout << temp[0] << '\n';
    cout << sum << '\n';
}