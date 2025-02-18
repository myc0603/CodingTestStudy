#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cout << n << m;

    // string mons[n+1];
    // for (int i = 1; i <= n; i++) {
    //     cin >> mons[i];
    // }

    // for (int i = 0; i < m; i++) {
    //     string s;
    //     cin >> s;
    //     int index = atoi(s.c_str());
    //     if (index == 0) {
    //         for (int j = 1; j <= n; j++) {
    //             if (mons[j].compare(s) == 0) {
    //                 cout << j;
    //             }
    //         }
    //     } else {
    //         cout << mons[index];
    //     }
    // }
    string monsArr[n+1];
    map<string, int> monsMap;
    
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        monsMap.insert({s, i});
        monsArr[i] = s;
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        int index = atoi(s.c_str());
        if (index == 0) {
            cout << monsMap[s];
        } else {
            cout << monsArr[index];
        }
    }
}