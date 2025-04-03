#include <iostream>
using namespace std;

int main() {
    int t; cin >> t;
    string ans;
    while (t--) {
        int h, w, n;
        cin >> h >> w >> n;
        string floor = to_string(n % h == 0 ? h : n % h);
        string idx = to_string((n - 1) / h + 1);
        if (idx.length() == 1) idx = "0" + idx;
        ans += floor + idx + '\n'; 
    }
    cout << ans;
}