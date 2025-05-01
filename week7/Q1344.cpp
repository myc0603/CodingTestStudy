#include <iostream>
#include <math.h>
using namespace std;

int nCr(int n, int r) {
    int result = 1;
    if (r > n / 2) r = n - r;
    int k = 1;
    while (k <= r) {
        result = result * n-- / k++;
    }
    return result;
}

double probOf(double p, int cnt) {
    return nCr(18, cnt) * pow(p, cnt) * pow(1 - p, 18 - cnt);
}

int main() {
    double pA, pB;
    cin >> pA >> pB;

    double a = 0, b = 0;
    int primes[] = {2, 3, 5, 7, 11, 13, 17};
    for (int prime : primes) {
        a += probOf(pA / 100, prime);
        b += probOf(pB / 100, prime);
    }

    double ans = a + b - a * b;
    cout << ans;
}