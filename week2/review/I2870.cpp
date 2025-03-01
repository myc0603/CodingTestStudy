#include <bits/stdc++.h>
using namespace std;

bool cmp(string &s1, string &s2) {
    if (s1.size() == s2.size()) {
        return s1 < s2;
    }
    return s1.size() < s2.size();
}

bool isNumber(char c) {
    return '0' <= c && c <= '9';
}

void append(string &num, vector<string> &nums) {
    if (num.size()) {
        while (num[0] == '0' && num.size() != 1) {
            num.erase(num.begin());
        }
        nums.push_back(num);
        num = "";
    }
    
}

int main() {
    int n; cin >> n;

    vector<string> nums;
    while (n--) {
        string s; cin >> s;

        string num;
        for (char c : s) {
            if (isNumber(c)) {
                num += c;
            } else {
                append(num, nums);
            }
        }
        append(num, nums);
    }
    
    sort(nums.begin(), nums.end(), cmp);

    for (string s : nums) {
        cout << s << '\n';
    }
}