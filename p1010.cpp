#include <iostream>
using namespace std;

int sol(int n, int m) {
    int ans = 1;
    int j = 1;
    for (int i = m - n + 1; i <= m; i++) {
        ans *= i;
        ans /= j;
        j++;
    }
    return ans;
}

int main() {
    int t, n, m;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        cout << sol(n, m) << '\n';
    }
}