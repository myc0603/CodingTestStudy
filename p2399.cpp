#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int v[n] = {};
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int sum = 0;
    for (int i : v) {
        for (int j : v) {
            sum += i > j ? i - j : j - i;
        }
    }
    cout << sum;
    return 0;
}