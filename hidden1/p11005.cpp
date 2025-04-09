#include <bits/stdc++.h>
using namespace std;
int n, b; string ans;
char get(int n) {
    if (0 <= n && n <= 9) return '0' + n;
    return 'A' + n - 10;
}
int main() {
    cin >> n >> b;
    while (n) {
        ans += get(n % b);
        n /= b;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}