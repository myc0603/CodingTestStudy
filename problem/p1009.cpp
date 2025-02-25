#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        int rem = 1;
        for (int i = 0; i < b; i++) {
            rem = rem * a % 10;
        }
        cout << rem << '\n';
    }
}