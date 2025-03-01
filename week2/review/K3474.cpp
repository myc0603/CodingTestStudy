#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    
    string ans;
    while (t--) {
        int n; cin >> n;

        int temp = 5;
        int cnt = 0;
        while (temp <= n) {
            cnt += n / temp;
            temp *= 5;
        }
        ans += to_string(cnt) + '\n';
    }
    cout << ans;
}