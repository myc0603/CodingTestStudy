#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    int s = 0;
    string ans;
    while (n--) {
        string command; cin >> command;
        int x;
        if (command == "add") {
            cin >> x;
            s |= (1 << x);
        } else if (command == "remove") {
            cin >> x;
            s &= ~(1 << x);
        } else if (command == "check") {
            cin >> x;
            // if (s & (1 << x)) {
            //     cout << 1 << '\n';
            // } else {
            //     cout << 0 << '\n';
            // }
            ans += s & (1 << x) ? to_string(1) + '\n' : to_string(0) + '\n';
            if (ans.length() > 100000) {
                cout << ans;
                ans = "";
            }
        } else if (command == "toggle") {
            cin >> x;
            s ^= (1 << x);
        } else if (command == "all") {
            s = (1 << 22) - 1;
        } else if (command == "empty") {
            s = 0;
        }
    }
    cout << ans;
}