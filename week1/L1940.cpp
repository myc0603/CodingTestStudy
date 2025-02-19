#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int comp[n];
    for (int i = 0; i < n; i++) {
        cin >> comp[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (comp[i] + comp[j] == m) {
                cnt++;
            }
        }
    }
    cout << cnt;
}