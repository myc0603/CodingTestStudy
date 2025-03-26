#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    bool s[21] = {};
    string ans;
    while (n--) {
        string command; cin >> command;
        int x;
        if (command == "add") {
            cin >> x;
            s[x] = true;
        } else if (command == "remove") {
            cin >> x;
            s[x] = false;
        } else if (command == "check") {
            cin >> x;
            ans += to_string(s[x]) + '\n';
            if (ans.length() > 100000) {
                cout << ans;
                ans = "";
            }
        } else if (command == "toggle") {
            cin >> x;
            s[x] = s[x] ? 0 : 1;
        } else if (command == "all") {
            fill(s, s + 21, true);
        } else if (command == "empty") {
            fill(s, s + 21, false);
        }
    }
    cout << ans;
}