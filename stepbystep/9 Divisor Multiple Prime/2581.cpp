#include <iostream>
using namespace std;
bool isPrime[10002];
int main() {
    fill(isPrime, isPrime + 10002, true);
    isPrime[1] = false;
    for (int i = 2; i <= 100; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= 10000; j += i) {
            isPrime[j] = false;
        }
    }

    int n, m;
    cin >> n >> m;
    int sum = 0, minPrime;
    for (int i = n; i <= m; ++i) {
        if (isPrime[i]) {
            if (sum == 0) minPrime = i;
            sum += i;
        }
    }
    
    if (sum) cout << sum << '\n' << minPrime;
    else cout << -1;
}