#include <iostream>
using namespace std;
const string s1 = "Equilateral", s2 = "Isosceles", s3 = "Scalene", s4 = "Error";
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b + c != 180) cout << s4;
    else if (a == b && b == c) cout << s1;
    else if (a == b || b == c || c == a) cout << s2;
    else cout << s3;
}