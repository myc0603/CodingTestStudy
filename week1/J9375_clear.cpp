#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    while (n--) {
        int m;
        cin >> m;

        map<string, int> wearMap;
        for (int j = 0; j < m; j++) {
            string s, wearKind;
            cin >> s >> wearKind;
            wearMap[wearKind]++;
        }
        int ans = 1;
        for (auto val : wearMap) {
            ans *= val.second + 1;
        }
        ans -= 1;
        cout << ans << '\n';
    }
}