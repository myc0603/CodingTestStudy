#include <iostream>
using namespace std;

int capA, capB, endA, endB;

// recursive algorithm
int gcd1(int a, int b) {
    int r = a % b;
    if (r == 0) return b;
    return gcd1(b, r);
}

// iterative algorithm
int gcd2(int a, int b) {
    int r = a % b;
    while (r != 0) {
        a = b, b = r;
        r = a % b;
    }
    return b;
}

int main() {
    cin >> capA >> capB >> endA >> endB;
}