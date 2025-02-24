#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t; cin >> t;
    string result = "";
    while (t--) {
        int n; cin >> n;
        
        int cnt = 0;
        long long d = 5;
        while (d < n) {
            cnt += n / d;
            d *= 5;
        }
        result += to_string(cnt) + '\n';
    }
    cout << result;
}