#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;

int n, k, a, psum[200003];
unordered_map<ll, ll> counts;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll cnt = 0;
    cin >> n >> k;
    ++counts[k]; // psum[0]+k == k
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        psum[i] = psum[i-1] + a;
        cnt += counts[psum[i]];
        ++counts[psum[i] + k];
    }
    cout << cnt;
}