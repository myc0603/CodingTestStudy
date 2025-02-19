#include <bits/stdc++.h>
using namespace std;

// have to find counterExample
// 10 1
// 1 2 3 4 5 6 7 8 9 10
// -> 9
int main() {
    int n, k;
    cin >> n >> k;

    int prefixSum[n] = {};
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (i == 0) {
            prefixSum[i] = num;
            continue;
        }
        prefixSum[i] = prefixSum[i-1] + num;
    }

    int max = prefixSum[k-1];
    // cout << "0 max: " << max << '\n'; 
    for (int i = 1; i <= n-k; i++) {
        int temp = prefixSum[i-1+k] - prefixSum[i-1];
        max = max > temp ? max : temp;
        // cout << i << " max: " << max << '\n'; 
    }
    cout << max;
}