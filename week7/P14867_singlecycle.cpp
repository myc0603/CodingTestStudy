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

    int g = gcd2(capA, capB);
    
    // 둘 중 하나는 꽉 차있거나 비어있고, 나머지 하나는 g의 배수
    bool impossible = false;
    if (endA == 0 || endA == capA) {
        if (endB % g != 0) impossible = true;
    } else {
        if (endA % g != 0 || (0 < endB && endB < capB)) impossible = true;
    }
    if (impossible) {
        cout << -1;
        return 0;
    }

    if (endA == capA && endB == capB) {
        cout << 2;
        return 0;
    }

    int cycleLength = 2 * (capA + capB) / g - 1;
    int a = 0, b = 0;
    int cnt = 0;
    for (; a != endA || b != endB; ++cnt) {
        if (a == 0) { // fill A
            a = capA;
        } else if (b == capB) { // empty B
            b = 0;
        } else { // move A to B
            if (a + b < capB) {
                b += a;
                a = 0;
            } else {
                a += b - capB;
                b = capB;
            }
        }
    }

    cout << min(cnt, cycleLength - cnt);
}