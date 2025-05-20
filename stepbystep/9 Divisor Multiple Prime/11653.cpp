#include <iostream>
#include <vector>
using namespace std;

int n, isPrime[10000003];
vector<int> primes;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    if (n == 1) return 0;
    fill(isPrime,isPrime + 10000003, true);
    isPrime[1] = 1;

    for (int i = 2; i * i <= n; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            isPrime[j] = false;
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) primes.push_back(i);
    }

    int cur = 0;
    while (!isPrime[n]) {
        while (n % primes[cur]) {
            ++cur;
        }
        n /= primes[cur];
        cout << primes[cur] << '\n';
    }
    cout << n;
}