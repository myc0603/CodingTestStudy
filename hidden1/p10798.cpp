#include <iostream>
#include <algorithm>
using namespace std;

string s[5];

int main() {
    int max_length = 0;
    for (int i = 0; i < 5; i++) {
        cin >> s[i];
        int len = s[i].length();
        max_length = max(max_length, len);
    }

    string ans;
    for (int j = 0; j < max_length; j++) {
        for (int i = 0; i < 5; i++) {
            if (s[i].length() <= j) continue;
            ans += s[i][j];
        }
    }
    cout << ans;
}