#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;

int n, k, a[200003], psum[200003];
unordered_map<ll, ll> counts;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        psum[i] = psum[i-1] + a[i];
        ++counts[psum[i] + k];
    }

    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += counts[psum[i]];
    }
    cout << cnt;
}