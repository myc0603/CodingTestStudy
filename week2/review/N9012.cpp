#include <iostream>
using namespace std;

int main() {
    int t; cin >> t;
    string ans;
    while (t--) {
        string s; cin >> s;
        bool valid = true;
        int stkSize = 0;
        for (char c : s) {
            if (c == '(') stkSize++;
            else if (stkSize) stkSize--;
            else {
                valid = false;
                break;
            }
        }
        ans += valid && stkSize == 0 ? "YES\n" : "NO\n";
    }
    cout << ans;
}