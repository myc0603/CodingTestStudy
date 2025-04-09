#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;
const int MAX = 1001;

long long fact[MAX];

// 모듈러 거듭제곱
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

// 모듈러 조합 함수
long long nCr_mod(int n, int r) {
    if (r > n) return 0;
    long long numerator = fact[n];
    long long denominator = (fact[r] * fact[n - r]) % MOD;
    return numerator * mod_pow(denominator, MOD - 2, MOD) % MOD;
}

int main() {
    // 팩토리얼 미리 계산
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    ///////////////////////////

    int n; cin >> n;

    long long ans = 0;
    int r = 0;
    while (n >= r) {
        ans += nCr_mod(n, r);
        ans %= 10007;
        n--; r++;
    }
    cout << ans;
    return 0;
}
