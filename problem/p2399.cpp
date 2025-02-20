#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sum += a[i] > a[j] ? a[i] - a[j] : a[j] - a[i];
        }
    }
    cout << sum * 2 << '\n';
    return 0;
}