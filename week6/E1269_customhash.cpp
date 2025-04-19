#include <iostream>
#include <unordered_set>
#include <chrono>
using namespace std;

struct CustomHash {
    static uint64_t splitmix64(uint64_t x) {
        // https://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n, m;
unordered_set<int, CustomHash> a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        if (a.find(x) != a.end()) cnt++;
    }

    cout << n + m - 2 * cnt;
}