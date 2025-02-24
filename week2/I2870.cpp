#include <bits/stdc++.h>
using namespace std;

bool comp(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return s1.size() < s2.size();
    } else {
        return s1 < s2;
    }
}

bool isNumber(char c) {
    return '0' <= c && c <= '9';
}

void append(string num, vector<string>& ans) {
    while (num[0] == '0' && num.size() != 1) {
        num = num.substr(1);
    }
    // cout << "    ans.push_back(num): " << num << '\n';
    ans.push_back(num);
}

int main() {
    int n; cin >> n;
    
    vector<string> ans;

    while (n--) {
        string s; cin >> s;
        // cout << "string: " << s << '\n';
        string num = "";
        for (char c : s) {
            if (isNumber(c)) num += c;
            else {
                if (num.size()) {
                    append(num, ans);
                }
                num = "";
            }
        }
        if (num.size()) {
            append(num, ans);
        }
    }

    sort(ans.begin(), ans.end(), comp);

    // cout << "\nprint answer\n";
    for (auto s : ans) {
        cout << s << '\n';
    }

}