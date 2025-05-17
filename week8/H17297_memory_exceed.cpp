#include <iostream>
using namespace std;
const string str1 = "Messi", str2 = "Gimossi";
int main() {
    string s1 = "M", s2 = "MG";
    int len1 = 5, len2 = 12;
    int len = len1 + len2 + 1;
    string s;
    while (len <= (1 << 30)) {
        s = s2; s += s1;
        s1 = s2;
        s2 = s;
        len1 = len2;
        len2 = len;
        len = len1 + len2 + 1;
    }
    int m; cin >> m;
    int cnt = 0;
    char ans;
    for (int i = 0; i < s.size(); ++i) {
        int l = s[i] == 'M' ? 5 : 7;
        if (cnt + l + 1 < m) cnt += l;
        else if (cnt + l + 1 == m) {
            ans = ' ';
            break;
        } else { // cnt + l >= m
            int idx = m - cnt - 1;
            ans = (s[i] == 'M' ? str1 : str2)[idx];
            break;
        }
        ++cnt;
    }
    if (ans == ' ') cout << "Messi Messi Gimossi";
    else cout << ans;
}