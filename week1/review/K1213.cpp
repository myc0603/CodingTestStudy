#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string impo = "I'm Sorry Hansoo";

    int cnt[26] = {};
    for (char c: s) {
        cnt[c-'A']++;
    }
    
    // cnt[26]기반으로 팰린드롬 만들면 됨
    // 만들면서 oddNum을 체크해서 2이상이 되면 gg
    int oddNum = 0;
    string ret;
    char mid;
    for (int i = 25; i >= 0; i--) {
        int num = cnt[i];
        char c = i + 'A';
        for (int j = 0; j < num/2; j++) {
            ret = c + ret + c;
        }
        if (num % 2) {
            oddNum++;
            mid = c;
        }
    }
    if (oddNum >= 2) ret = impo;
    else if (oddNum == 1) ret.insert(ret.begin() + s.size()/2, mid);
    cout << ret << '\n';
}