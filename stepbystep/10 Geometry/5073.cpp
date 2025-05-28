#include <iostream>
using namespace std;
const string eq = "Equilateral", is = "Isosceles", sc = "Scalene", in = "Invalid";
int main() {
    while (true) {
        int a, b , c;
        cin >> a >> b >> c;
        if (a == 0) break;
        if (2 * max(a, max(b, c)) >= a + b + c) cout << in << '\n';
        else if (a == b && b == c) cout << eq << '\n';
        else if (a == b || b == c || c == a) cout << is << '\n';
        else cout << sc << '\n';
    }
}