#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> primes;

void buildPrimes() {
    vector<bool> isPrime(n + 1, true);
    for (int i = 2; i * i <= n; i++) {
        if (!isPrime[i]) continue;
        // primes.push_back(i);
        for (int num = i * i; num <= n; num += i) {
            isPrime[num] = false;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}

int main() {
    cin >> n;
    buildPrimes();

    int cnt = 0;

    for (int i = 0; i < primes.size(); i++) {
        int l = i;
        
        int sum = 0;
        for (int r = l; r < primes.size() && sum < n; r++) {
            sum += primes[r];
        }

        if (sum == n) cnt++;
    }

    // int l = 0;
    // int r = 0;
    // int sum = 0;
    // while (r < primes.size()) {
    //     sum += primes[r];
    //     if (sum < n) r++;
    //     else {
    //         if (sum == n) cnt++;
    //         r = ++l;
    //         sum = 0;
    //     }
    // }

    cout << cnt;
}