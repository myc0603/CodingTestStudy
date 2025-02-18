#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        cin.ignore();
        if (m == 0) {
            cout << 0;
            continue;
        }
        map<string, int> wearMap;
        for (int j = 0; j < m; j++) {
            printf("loop: %d/%d\n", j, m);
            string s;
            getline(cin, s);
            int index = s.find(' ');
            string wearKind = s.substr(index + 1);
            wearMap[wearKind]++;
            cout << "wearKind: " + wearKind + ":"<< wearMap[wearKind] << '\n';
        }
        int ans = 1;
        for (auto it = wearMap.begin(); it != wearMap.end(); it++) {
            cout << "wearing num: " << it -> second << '\n';
            ans *= (it -> second + 1);
        }
        ans -= 1;
        cout << ans;
    }
}