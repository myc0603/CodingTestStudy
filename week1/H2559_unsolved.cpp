#include <bits/stdc++.h>
using namespace std;

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

    int max = prefixSum[k];
    for (int i = 1; i < n-k; i++) {
        int temp = prefixSum[i+k] - prefixSum[i];
        max = max > temp ? max : temp;
    }
    cout << max;
}