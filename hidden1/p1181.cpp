#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<string> v;

bool cmp(string s1, string s2) {
    if (s1.length() == s2.length()) return s1 < s2;
    return s1.length() < s2.length();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    while (n--) {
        string s; cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    string ans, prev;
    for (string s : v) {
        if (s == prev) continue;
        ans += s + '\n';
        prev = s;
    }
    cout << ans;
}