#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int cnt[26] = {};
    for (char c: s) {
        cnt[c-'a']++;
    }
    for (int num : cnt) {
        cout << num << ' ';
    }
}