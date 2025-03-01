#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// 모음 하나 이상
bool cond1(string s) {
    for (char c : s) {
        if (isVowel(c)) {
            return true;
        }
    }
    return false;
}

// 모음 3개 연속, 자음 3개 연속 X
bool cond2(string s) {
    int cnt = 0;
    char prev = 'a'-1;
    for (char c : s) {
        cnt = isVowel(prev) == isVowel(c) ? cnt + 1 : 1;
        if (cnt >= 3) {
            return false;
        }
        prev = c;
    }
    return true;
}

// e,o 빼고 같은 글자 연속 x
bool cond3(string s) {
    char prev = 'a'-1;
    for (char c : s) {
        if (prev == c && c != 'e' && c != 'o') {
            return false;
        }
        prev = c;
    }
    return true;
}

int main() {
    string ans;
    while (true) {
        string s; cin >> s;
        if (s == "end") {
            break;
        }

        ans += "<" + s + "> is ";
        ans += cond1(s) && cond2(s) && cond3(s) ? "acceptable.\n" : "not acceptable.\n";
        // cout << cond1(s) << '\n';
        // cout << cond2(s) << '\n';
        // cout << cond3(s) << '\n';
    }
    cout << ans;
}