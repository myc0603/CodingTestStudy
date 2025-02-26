#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    string ans;
    while (t--) {
        int a, b;
        cin >> a >> b;

        // a^b % 10
        int rem = 1;
        int temp = a % 10; // int도 될 듯
        while (b) {
            if (b % 2) {
                rem = rem * temp % 10;
            }
            temp = temp * temp % 10;
            b /= 2;
        }

        rem = !rem ? 10 : rem;
        ans += to_string(rem) + '\n';
    }
    cout << ans;
}