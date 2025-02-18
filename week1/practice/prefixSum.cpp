#include <bits/stdc++.h>

using namespace std;

int main() {

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int prefixSum[10];

    prefixSum[0] = a[0];
    for (int i = 1; i < 10; i++) {
        prefixSum[i] = prefixSum[i-1] + a[i];
    }
    for (int i = 0; i < 10; i++) {
        cout << prefixSum[i] << '\n';
    }

    return 0;
}