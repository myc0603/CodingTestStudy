#include <bits/stdc++.h>
using namespace std;

bool matchPattern(string pattern, string s) {
    int pos = pattern.find('*');
    string pre = pattern.substr(0, pos);
    string suf = pattern.substr(pos + 1);

    if (s.size() < pre.size() + suf.size()) {
        return false;
    }

    int sufIdx = s.size() - suf.size();
    return s.find(pre) == 0 && s.find(suf, sufIdx) == sufIdx;
}

int main() {
    int n;
    cin >> n;
    string pattern;
    cin >> pattern;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string output = matchPattern(pattern, s) ? "DA" : "NE";
        cout << output << '\n';
    }
}