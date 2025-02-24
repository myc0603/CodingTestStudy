#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// 최소 하나의 모음 포함
bool cond1(string s) {
    for (char c : s) {
        if (isVowel(c)) return true;
    }
    return false;
}

// 모음 연속 3개 이상 또는 자음 연속 3개 이상 안됨
bool cond2(string s) {
    bool before = isVowel(s[0]);
    int cnt = 0;
    for (auto c : s) {
        bool cur = isVowel(c);
        cnt = before == cur ? cnt + 1 : 1;
        if (cnt >= 3) return false;
        before = cur;
    }
    return true;
}

// 같은 글자 연속 안되는데 ee, oo는 됨
bool cond3(string s) {
    char before = 'a'-1;
    for (auto c: s) {
        if (before == c) {
            if (c != 'e' && c != 'o') {
                return false;
            }
        }
        before = c;
    }
    return true;
}

int main() {
    while (true) {
        string s;
        cin >> s;
        if (s == "end") break;
        string ans = "<" + s + "> is ";
        ans += cond1(s) && cond2(s) && cond3(s) ? "acceptable.\n" : "not acceptable.\n";
        cout << ans;
        // cout << cond1(s) << '\n';
        // bool b = cond2(s);
        // cout << "check cond2: ";
        // cout << b << '\n';
        // cout << cond3(s) << '\n';
    }
}