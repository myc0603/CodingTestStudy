#include <bits/stdc++.h>
using namespace std;

/**
 * 패턴에 *의 개수가 무작위일 때
 */

bool matchPattern(string pattern, string input) {
    // split
    int index = pattern.find('*');

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