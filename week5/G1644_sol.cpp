#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> primes;

void buildPrimes() {
    vector<bool> isPrime(n + 1, true);
    for (int i = 2; i * i <= n; i++) {
        if (!isPrime[i]) continue;
        for (int num = i * i; num <= n; num += i) {
            isPrime[num] = false;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    buildPrimes();
    for (int num : primes) cout << num << ' '; cout << '\n';
    int cnt = 0;
    int l = 0, r = -1;
    int cur = 0;
    // while (r + 1 < primes.size() + 1 && l < primes.size()) {
    // while (r < primes.size() && l < primes.size()) {
    while (r < (int) primes.size() && l < primes.size()) {
    // while (l < primes.size()) {
        cout << "l,r,cur: " << l << ' ' << r << ' ' << cur << '\n';
        if (cur == n) cnt++;
        if (cur <= n && r + 1 < primes.size()) { // -> 어차피 r은 여기 조건 때문에 primes.size()를 벗어나지 못함
            r++;
            cur += primes[r];
        } else { // cur > n
            cur -= primes[l];
            l++;
        }
    }
    cout << cnt;
}