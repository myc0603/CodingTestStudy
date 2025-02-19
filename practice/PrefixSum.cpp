#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int psum[n+1] = {};
    for (int i = 1; i <= n; i++) {
        cin >> psum[i];
    }

    int max = psum[k];
    for (int i = k + 1; i <= n; i++) {
        int temp = psum[i] - psum[i-k];
        max = max > temp ? max : temp;
    }
    for (int i = 1; i <= n-k; i++) {
        int temp = psum[k+i] - psum[i];
        max = max > temp ? max : temp;
    }
    cout << max;
}