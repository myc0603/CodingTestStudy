#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int a[26] = {};
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int charNum = s[0] - 'a';
        a[charNum]++;
    }

    bool surrender = false;
    for (int i = 0; i < 26; i++) {
        if (a[i] >= 5) {
            cout << (char) (i + 'a');
            surrender = true;
        }
    }
    if (!surrender) {
        cout << "PREDAJA";
    }
}