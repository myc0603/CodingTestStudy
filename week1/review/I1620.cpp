#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string monArr[n+1];
    map<string, int> monMap; // 포켓몬 이름, 인덱스

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        monArr[i] = s;
        monMap[s] = i;
    }

    string result;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        int idx = atoi(s.c_str());
        if (idx == 0) { // 문자가 들어올 때
            result += to_string(monMap[s]);
        } else {
            result += monArr[idx];
        }
        result += '\n';
    }
    cout << result;
}