#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m; // 1 ~ 10만
    cin >> n >> m;

    string monsArr[n+1]; // 숫자 나오는 문제 맞추는 용도
    map<string, int> monsMap; // 포켓몬 이름 나오는 문제 맞추는 용도도
    
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        monsMap.insert({s, i});
        monsArr[i] = s;
    }

    // monsMap, monsArr print
    cout << "monsMap" << '\n';
    for (auto it = monsMap.begin(); it != monsMap.end(); it++) {
        cout << it -> first << " : " << it -> second << '\n';
    }
    cout << "monsArr" << '\n';
    for (int i = 1; i <= n; i++) {
        cout << monsArr[i] << '\n';
    }
    cout << "==========================\n";
    
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        int index = atoi(s.c_str());
        if (index == 0) {
            cout << monsMap[s] << '\n';
        } else {
            cout << monsArr[index] << '\n';
        }
    }
}