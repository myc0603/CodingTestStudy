#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        if (m == 0) {
            cout << 0;
            break;
        }
        map<string, int> wearMap;
        for (int j = 0; j < m; j++) {
            string s;
            getline(cin, s);
            int index = s.find(' ');
            string wearKind = s.substr(index + 1);
            wearMap[wearKind]++;
        }
        int ans = 1;
        for (auto it = wearMap.begin(); it != wearMap.end(); it++) {
            ans *= (it -> second + 1);
        }
    }
}