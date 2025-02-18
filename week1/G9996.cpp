#include <bits/stdc++.h>
using namespace std;

bool matchPattern(string pattern, string input) {

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