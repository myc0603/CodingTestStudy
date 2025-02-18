#include <bits/stdc++.h>
using namespace std;

bool check(const string& s) {
    int len = s.size();
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len-1-i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    cin >> s;

    bool notFound = true;
    sort(s.begin(), s.end());
    do {
        // 펠린드롬인지 확인해서 맞으면 출력하고 break;
        if (check(s)) {
            cout << s;
            notFound = false;
            break;
        }
    } while (next_permutation(s.begin(), s.end()));
    if (notFound) {
        cout << "I'm Sorry Hansoo";
    }
}