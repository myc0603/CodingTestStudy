#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        map<string, int> kindMap;
        while (n--) {
            string s, kind;
            cin >> s >> kind;

            kindMap[kind]++;
        }
        int ans = 1;
        for (auto num : kindMap) {
            ans *= num.second + 1;
        }
        cout << ans - 1 << '\n';
    }
}