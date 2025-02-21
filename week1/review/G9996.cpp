#include <bits/stdc++.h>
using namespace std;
bool match(string pat, string s) {
    int pos = pat.find('*');
    string pre = pat.substr(0, pos);
    string suf = pat.substr(pos + 1);

    if (s.size() < pre.size() + suf.size()) return false;
    bool cond1 = s.find(pre) == 0;
    int sufIdx = s.size() - suf.size();
    bool cond2 = s.find(suf, sufIdx) == sufIdx;
    return cond1 && cond2;
}
int main() {
    int n; cin >> n;
    string pat; cin >> pat;
    string ans;
    while (n--) {
        string s; cin >> s;
        ans += match(pat, s) ? "DA\n" : "NE\n";
    }
    cout << ans;
}