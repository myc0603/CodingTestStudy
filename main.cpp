#include <bits/stdc++.h>
using namespace std;

bool matchPattern(string pattern, string input) {
    // split
    int index = pattern.find('*');
    string front = pattern.substr(0, index);
    string back = pattern.substr(index + 1);
    bool f = input.find(front) == 0;
    // input.find(back) 할때 뒤에서부터 찾아야됨됨
    int backPos = input.size() - back.size();
    bool b = input.find(back, backPos) == backPos;
    if (index == 0) { // *xxx
        return b;
    } else if (index == (pattern.size() - 1)) { // xxx*
        return f;
    } else {
        return f && b;
    }

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
        cout << output;
    }
}