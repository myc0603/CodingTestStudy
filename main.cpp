#include <bits/stdc++.h>
using namespace std;

bool isGood(string s) {
    if (s.size() == 0) {
        return true;
    }
    char first = s[0];
    auto next = s.find(first, 1);
    if (next == 1 && s.size() == 2) {
        return true;
    }
    if (next == string::npos){
        return false;
    }
    return isGood(s.substr(1, next - 1)) && isGood(s.substr(next + 1));
}
int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (isGood(s)) {
            cnt++;
        }
    }
    cout << cnt;
}