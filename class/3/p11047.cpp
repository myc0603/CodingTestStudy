#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for (int &c : coins) cin >> c;

    int cnt = 0;
    for (int i = n - 1; k && i >= 0; i--) {
        cnt += k / coins[i];
        k -= coins[i] * (k / coins[i]);
    }
    cout << cnt;
}