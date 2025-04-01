#include <iostream>
using namespace std;

// 나머지
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a + b) % c << '\n';
    cout << ((a % c) + (b % c)) % c << '\n';
    
    cout << (a * b) % c << '\n';
    cout << ((a % c) * (b % c)) % c << '\n';
}